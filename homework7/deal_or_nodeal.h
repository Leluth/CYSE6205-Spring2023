#pragma once

using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class deal_or_nodeal{
private:
	static bool interactive;
	static int chosen_suitcase;
	static vector<double> money;
	static vector<double> suitcases;
	static vector<int> remaining_suitcases;

	static void init_game();
	static bool new_round(const int round, const int num);
	static string print_remaining_suitcases();
	static void select_suitcase();
	static int input_suitcase();
	static bool verify_suitcase_input(const string& s);

public:
	static void get_interactive_or_computer();
	static void play_a_game();
	static void play_until_millionare();
	static void play_until_bankrupt();
};