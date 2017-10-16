#pragma once
#include <vector>

using namespace std;

class OutputFormatter // singleton
{
public:
	static OutputFormatter& GetInstance() {
		static OutputFormatter instance;
		return instance;
	}
	~OutputFormatter() {};
	OutputFormatter(OutputFormatter const&) = delete;
	void operator=(OutputFormatter const&) = delete;

	void PrintTable(const bool separateValuesByLine = false);
	void PrintSlow(const string& text);
	
	void NewTable();
	// TODO: change to vector<vector<string>>
	void SetTableColumnNames(const vector<string>& namesVec) { m_ColumnNameVec = namesVec; }
	template<typename T>
	void SetTableValues(const T& t);
	template<typename T, typename ...R>
	void SetTableValues(const T& t, const R& ...r);


private:
	OutputFormatter() {};

	void PrintHorLine() const;
	void CalculateColumnWidths();
	int GetNrOfRows() const;

	// members
	vector<string> m_ColumnNameVec;
	vector<vector<string>> m_ColumnValueVec;
	vector<int> m_ColumnWidthVec;
};

template<typename T>
inline void OutputFormatter::SetTableValues(const T& t)
{
	m_ColumnValueVec.push_back(t);
}

template<typename T, typename ...R>
inline void OutputFormatter::SetTableValues(const T& t, const R& ...r)
{
	SetTableValues(t);
	SetTableValues(r...);
}
