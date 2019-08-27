#include "pch.h"
#include "Block.h"
#include "Pointer.h"
#include "Mine.h"

#include "GameManager.h"

Block::Block(int x, int y, eType type) : MapObject(x, y, type) {}

Block::~Block() {}

void Block::Interact(Pointer* MyPointer) { Interact(MyPointer->GetPos().X, MyPointer->GetPos().Y); }

void Block::Interact(int x, int y) {

	if (state == eState::None) {

		state = eState::Pushed;
		Push(x, y);
	}
}

void Block::Chain(int x, int y) {

	if (state == eState::None || state == eState::Flagged) {

		state = eState::Pushed;
		Push(x, y);
	}
}

void Block::Push(int x, int y) {

	int s = (int)GameMng()->MapSize;

	for (int i = y - 1; i <= y + 1; ++i) {
		for (int j = x - 1; j <= x + 1; ++j) {

			if ((0 <= i && i < s) && (0 <= j && j < s)) {

				if (GameMng()->Map[i][j] == eType::Mine) { ++MineCnt; }
			}
		}
	}

	if (MineCnt != 0) { return; }

	else {
		for (int i = y - 1; i <= y + 1; ++i) {
			for (int j = x - 1; j <= x + 1; ++j) {

				if ((0 <= i && i < s) && (0 <= j && j < s)) {
					if (i != y || j != x) {

						for (auto r : GameMng()->Blocks) {

							if (r->IsCrossed(j, i) == true && r->state != eState::Pushed)
							{
								r->Chain(j, i);

								GameMng()->ObjState[r->GetPos().Y][r->GetPos().X] = r->state;

								GameMng()->RenderByType(r->GetPos().X, r->GetPos().Y);
							}
						}
					}
				}
			}
		}
	}
}