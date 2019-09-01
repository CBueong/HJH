#pragma once

//	Input
namespace Input {

	std::vector<std::vector<std::string>> testcase01
	{
		std::vector<std::string>{"3","2 9","4 3","14 9"},
		std::vector<std::string>{"1","1 1"},
		std::vector<std::string>{"2","1 1","5 5"},
	};

	std::vector<std::vector<std::string>> testcase02
	{
	std::vector<std::string>{"1 1 9 0 5"},
	std::vector<std::string>{"1 1 8 0 3"},
	std::vector<std::string>{"2 0 3 1 1"},
	};

	std::vector<std::vector<std::string>> testcase03
	{
	std::vector<std::string>{"10 5","3","6 5","0 4","8 0","2 0"},
	std::vector<std::string>{"10 5","3","10,0","10 5","5 0","0 0"},
	std::vector<std::string>{"10 5","2","6 5","8 0","2 0"},
	};

	std::vector<std::vector<std::string>> testcase04
	{
	std::vector<std::string>{"3","6 3 6","4 4 4","6 2 5"},
	std::vector<std::string>{"1","1 1 1"},
	std::vector<std::string>{"2","1 2 3","4 5 6"},
	};

	std::vector<std::vector<std::string>> testcase05
	{
	std::vector<std::string>{
		"3",
			"4 50",
			"2 160",
			"3 30",
			"1 60",
			"3 20",
			"1 100"
	},
	std::vector<std::string>{
		"3",
			"4 50",
			"2 160",
			"3 30",
			"1 60",
			"3 20",
			"1 100"
	},
	std::vector<std::string>{
		"3",
			"4 50",
			"2 160",
			"3 30",
			"1 60",
			"3 20",
			"1 100"
	},
	};

	std::vector<std::vector<std::string>> testcase06
	{
	std::vector<std::string>{
		"5",
			"35 91 15 85 73",
			"77 62 57 53 8",
			"28 90 66 97 47",
			"79 46 82 39 88",
			"24 19 12 7 75",
	},

	std::vector<std::string>{
		"5",
			"35 91 15 85 73",
			"77 62 57 53 8",
			"28 90 66 97 47",
			"79 46 82 39 88",
			"24 19 12 7 75",
	},

	};

	std::vector<std::vector<std::string>> testcase07
	{
	std::vector<std::string>{"17 40","80"},
	std::vector<std::string>{"23 30","31"},
	};

	std::vector<std::vector<std::string>> testcase08
	{
	std::vector<std::string>{
		"5",
			"70 180",
			"68 182",
			"82 188",
			"72 175",
			"46 155",
	},
	std::vector<std::string>{
		"2",
			"70 180",
			"68 182",
	},
	std::vector<std::string>{
		"3",
			"82 188",
			"72 175",
			"46 155",
	},

	};

	std::vector<std::vector<std::string>> testcase09
	{
	std::vector<std::string>{"2030"},
	std::vector<std::string>{"2019"},
	std::vector<std::string>{"2041"},
	};

	std::vector<std::vector<std::string>> testcase10
	{
	std::vector<std::string>{"5","6 9 5 7 4"},
	std::vector<std::string>{"5","1 2 3 4 5"},
	std::vector<std::string>{"5","5 4 3 2 1"},
	};

}

// 메인 인클루드 순서가 pch.h 보다 늦게 되므로 사용가능?