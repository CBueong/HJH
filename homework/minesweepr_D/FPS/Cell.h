#pragma once
class Cell
{
public:
	Cell(int a_x, int a_y, CellType a_CellType);
	~Cell();

	bool ToggleFlag();
	CellType OpenCell();
	TCHAR SetCellData();
	
	void Render();
	CellCoord GetCellCoord() const;

public:

	CellType m_CellType;
	size_t NearbyMines = 0;
	CellState m_CellState = CellState::eDefault;
	bool SafetyFlag = false;

private:
	// 셀의 형태 : 기본, 열림, 깃발표시
	
	OnCursor m_OnCursor = OnCursor::eFALSE;	
	
	TCHAR CellData = L'□';
	CellCoord m_CellCoord;
	/*int x1;
	int x2 = x1+ 1;
	int y;*/
};