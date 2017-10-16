#include "OutputFormatter.h"
#include <cstdarg>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <thread>
#include <chrono>

#include "Helpers.h"

using namespace std;

void OutputFormatter::PrintTable(const bool separateValuesByLine)
{
	CalculateColumnWidths();
	int nrOfRows = GetNrOfRows();

	const char sep = ' ';

	cout << endl;
	PrintHorLine();
	// Print column names
	for (size_t i = 0; i < m_ColumnNameVec.size(); i++)
	{
		cout << "| ";
		cout << left << setw(m_ColumnWidthVec[i]) << setfill(sep) << m_ColumnNameVec[i];
		cout << " ";
		if (i == m_ColumnValueVec.size() - 1)
			cout << "|";
	}

	cout << endl;
	PrintHorLine();
	// Print column values
	for (size_t row = 0; row < nrOfRows; row++)
	{
		for (size_t col = 0; col < m_ColumnValueVec.size(); col++)
		{
			cout << "| ";
			if(row < m_ColumnValueVec[col].size())
				cout << left << setw(m_ColumnWidthVec[col]) << setfill(sep) << m_ColumnValueVec[col][row];
			else
				cout << left << setw(m_ColumnWidthVec[col]) << setfill(sep) << "";
			cout << " ";
			if (col == m_ColumnValueVec.size() - 1)
				cout << "|";
		}
		cout << endl;
		if (separateValuesByLine)
			PrintHorLine();
	}
	if(!separateValuesByLine)
		PrintHorLine();
}

void OutputFormatter::PrintSlow(const string & text)
{
	for (int i = 0; i < text.length(); i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		system("cls");
		cout << text.substr(0, i);
	}
}

void OutputFormatter::NewTable()
{
	m_ColumnNameVec.clear();
	m_ColumnValueVec.clear();
}

void OutputFormatter::PrintHorLine() const
{
	for (size_t i = 0; i < m_ColumnNameVec.size(); i++)
	{
		cout << "+";
		cout << left << setw(m_ColumnWidthVec[i] + 2) << setfill('-') << "";
		cout << "";
		if (i == m_ColumnNameVec.size() - 1)
			cout << "+";
	}
	cout << endl;
}

void OutputFormatter::CalculateColumnWidths()
{
	int longestStringLength = 0;
	int nameLength = 0;
	int valueLength = 0;
	for (size_t i = 0; i < m_ColumnNameVec.size(); i++)
	{
		nameLength = m_ColumnNameVec[i].length();
		valueLength = GetLongestStringLength(m_ColumnValueVec[i]);
		if (i < m_ColumnWidthVec.size())
		{
			if (nameLength > valueLength)
				m_ColumnWidthVec[i] = nameLength;
			else
				m_ColumnWidthVec[i] = valueLength;
		}
		else
		{
			if(nameLength > valueLength)
				m_ColumnWidthVec.push_back(nameLength);
			else
				m_ColumnWidthVec.push_back(valueLength);
		}
	}
}

int OutputFormatter::GetNrOfRows() const
{
	int largestCount = 0;
	for (auto vec : m_ColumnValueVec)
	{
		if(vec.size() > largestCount)
			largestCount = vec.size();
	}
	return largestCount;
}