#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

struct line
{
	string name;
	string surname;
	short year;
	size_t size() const
	{
		return (sizeof(string) + name.size() + sizeof(string) + surname.size() + sizeof(int));
	}
};

bool operator < (const line& s1, const line& s2)
{
	return (s1.surname < s2.surname);
}

bool operator >(const line& s1, const line& s2)
{
	return (s1.surname > s2.surname);
}

ostream & operator<<(ostream & output, line const & str)
{
	output << str.surname << " " << str.name << " " << str.year;
	return output;
}

istream & operator>>(istream & input, line & str)
{
	input >> str.surname >> str.name >> str.year;
	return input;
}

bool operator != (line s, string str)
{
	return (s.surname != str);
}

struct s_i
{
	line s;
	ifstream *f;
	s_i(const line& s_, ifstream* f_) : s(s_), f(f_) {}
};

bool operator < (const s_i& s_i1, const s_i& s_i2)
{
	return (s_i1.s > s_i2.s);
}

void Vnesh_sort(const string input_name, const string output_name, const short mem_size)
{
	ifstream fin(input_name, ios::binary);
	if (!fin.is_open()) throw("file_not_open");
	ofstream fout(output_name, ios::binary);
	short k = 0;
	while (!fin.eof())
	{
		vector<line> v; line s;
		ofstream fout_(to_string(k + 1), ios::binary);
		for (unsigned long int size = 0; (size + 50) < mem_size * 1024 * 1024 * 0.65;)
		{
			if (!fin.eof() && (fin >> s) && (s != ""))  v.push_back(s);
			size += s.size();
		}
		sort(v.begin(), v.end());
		for (auto i : v)
		{
			if (i != "") fout_ << i << endl;
		}
		++k;
		fout_.close();
	}
	fin.close();
	priority_queue<s_i> pq;
	for (size_t i = 0; i < k; ++i)
	{
		ifstream* f_ = new ifstream(to_string(i + 1), ios::binary);
		line str;
		*f_ >> str;
		s_i si(str, f_);
		pq.push(si);
	}
	while (!pq.empty())
	{
		s_i si = pq.top();
		pq.pop();
		if (si.s != "") fout << si.s << endl;
		if (!(*si.f).eof() && (*si.f >> si.s))
		{
			pq.push(si);
		}
		else
		{
			(*(si.f)).close();
		}
	}
	for (size_t i = 0; i < k; ++i)
	{
		remove((to_string(i + 1)).c_str());
	}
	fout.close();
}

