#include "pch.h"
#include "Cell.h"
#include "GameManager.h"

Cell::Cell(int a_x, int a_y, CellType a_CellType) : m_CellType(a_CellType)
{
	m_CellCoord.x1 = a_x;
	m_CellCoord.x2 = a_x + 1;
	m_CellCoord.y = a_y;
}

Cell::~Cell()
{
}

bool Cell::ToggleFlag()
{
	if (m_CellState != CellState::eOpen) {
		SafetyFlag = !SafetyFlag;		
	}
	return SafetyFlag;
}

CellType Cell::OpenCell()
{
	if (SafetyFlag == true) { return m_CellType; }

	m_CellState = CellState::eOpen;
	return m_CellType;
}

TCHAR Cell::SetCellData()
{
	if (m_CellType == CellType::Normal) {
		if (m_CellState == CellState::eDefault) {
			CellData = L'¡à';
		}
		else if (m_CellState == CellState::eOpen) {
			switch (NearbyMines)
			{
			case 1: CellData = L'£±'; break;
			case 2: CellData = L'£²'; break;
			case 3: CellData = L'£³'; break;
			case 4: CellData = L'£´'; break;
			case 5: CellData = L'£µ'; break;
			case 6: CellData = L'£¶'; break;
			case 7: CellData = L'£·'; break;
			case 8: CellData = L'£¸'; break;
			default:CellData = L'¡¡'; break;
			}
		}
	}
	else if (m_CellType == CellType::Mine) {
		if (m_CellState == CellState::eDefault) {
			CellData = L'¡à';
		}
		else if (m_CellState == CellState::eOpen) {
			CellData = L'¢Í';
		}
	}

	if (SafetyFlag == true) {
		CellData = L'¢Ã';
	}

	return CellData;
}

void Cell::Render()
{	
	std::wcout << SetCellData();
}

CellCoord Cell::GetCellCoord() const
{
	return m_CellCoord;
}
