#include "deal_or_nodeal.h"

vector<double> deal_or_nodeal::money = { 0.01, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000 };
vector<double> deal_or_nodeal::suitcases = vector<double>();
vector<int> deal_or_nodeal::remaining_suitcases = vector<int>();
bool deal_or_nodeal::interactive = false;
int deal_or_nodeal::chosen_suitcase = 0;

const string INTERACTIVE = "i";
const string COMPUTER = "c";
const string DEAL = "d";
const string NO_DEAL = "n";
const int SHUFFLE_TIMES = 1000;

void deal_or_nodeal::init_game(){
    chosen_suitcase = 0;
    srand(time(NULL));
    remaining_suitcases.resize(money.size(), 0);
    for(int i = 0; i < remaining_suitcases.size(); i++){
        remaining_suitcases[i] = i + 1;
    }
    suitcases = money;
    for (int i = 0; i < SHUFFLE_TIMES; i++) {
        swap(suitcases[rand() % suitcases.size()], suitcases[rand() % suitcases.size()]);
    }
    cout << "---------------Initializing New Game---------------" << endl;
    cout << "Select ONE suitcase from " << print_remaining_suitcases() << endl;
    chosen_suitcase = input_suitcase();
    cout << "Your suitcase is: " << chosen_suitcase << endl;
}

bool deal_or_nodeal::new_round(const int round, const int num) {
    cout << "---------------ROUND NUMBER " << round << "-------------------" << endl;
    cout << "***Select " << num << " suitcases now****" << endl;
    bool deal = false;
    for (int i = 0; i < num && remaining_suitcases.size(); i++) {
        select_suitcase();
    }
    if (remaining_suitcases.size()) {
        vector<double> remaining_money = vector<double>();
        int banker_offer = 0;
        for (int suitcase_num : remaining_suitcases) {
            remaining_money.push_back(suitcases[suitcase_num - 1]);
            banker_offer += suitcases[suitcase_num - 1];
        }
        for (int j = 0; j < remaining_money.size() - 1; ++j) {
            int min = j;
            for (int i = j + 1; i < remaining_money.size(); ++i) {
                if (remaining_money.at(min) > remaining_money.at(i)) {
                    min = i;
                }
            }
            if (min != j) {
                swap(remaining_money.at(j), remaining_money.at(min));
            }
        }
        string s = "";
        for (int money_num : remaining_money) {
            if (s.size() > 0) {
                s += ",";
            }
            s += to_string(money_num);
        }
        cout << "Money left are: " << s << endl;
        banker_offer /= remaining_suitcases.size();
        cout << "Banker offer: " << banker_offer << endl;
        if (interactive) {
            string option;
            do {
                cout << "Deal[d] or NOdeal[n]: ";
            } while (cin >> option && !(option == DEAL || option == NO_DEAL));
            if (option == DEAL) {
                deal = true;
                cout << "You get the offer: " << banker_offer << endl;
            }
            else if (option == NO_DEAL) {
                deal = false;;
            }
            else {
                assert(false);
            }
        }
    }
    return !deal && remaining_suitcases.size();
}

string deal_or_nodeal::print_remaining_suitcases(){
    string s = "";
    for(int num: remaining_suitcases){
        if (s.size() > 0) {
            s += ",";
        }
        s += to_string(num);
    }
    return s;
}

void deal_or_nodeal::select_suitcase() {
    cout << "Select ONE suitcase from " << print_remaining_suitcases() << endl;
    int current_suitcase = input_suitcase();
    if (remaining_suitcases.size()) {
        cout << "You selected suitcase " << current_suitcase << " which has " << suitcases[current_suitcase - 1] << " dollars" << endl;
    }
    else {
        cout << "Last suitcase left is " << current_suitcase << " which has " << suitcases[current_suitcase - 1] << " dollars" << endl;
        cout << "Your suitcase has: " << suitcases[chosen_suitcase - 1] << " dollars" << endl;
    }
}

int deal_or_nodeal::input_suitcase() {
    int current_suitcase = 0;
    if (deal_or_nodeal::interactive) {
        string input;
        do {
            cout << "Select ONE suitcase from above:";
        } while (cin >> input && !verify_suitcase_input(input));
        current_suitcase = stoi(input);
    }
    else {
        current_suitcase = remaining_suitcases[rand() % remaining_suitcases.size()];
    }
    remaining_suitcases.erase(find(remaining_suitcases.begin(), remaining_suitcases.end(), current_suitcase));
    return current_suitcase;
}

bool deal_or_nodeal::verify_suitcase_input(const string& input){
    if (input.empty()) {
        return false;
    }
    for(const char &ch: input){
        if (!isdigit(ch)) {
            return false;
        }
    }
    int suitcase = stoi(input);
    for(int num: remaining_suitcases){
        if (suitcase == num) {
            return true;
        }
    }
    return false;
}

void deal_or_nodeal::get_interactive_or_computer() {
    string option;
    do {
        cout << "Interactive[i] or Computer[c]:";
    } while (cin >> option && !(option == INTERACTIVE || option == COMPUTER));
    if (option == INTERACTIVE) {
        interactive = true;
    }
    else if (option == COMPUTER) {
        interactive = false;;
    }
    else {
        assert(false);
    }
}

void deal_or_nodeal::play_a_game(){
    init_game();
    int round = 1, num = 6;
    while(new_round(round, num)) {
        round++;
        if (num > 1) {
            num--;
        }
    }
}

void deal_or_nodeal::play_until_millionare(){
    int count = 0;
    do {
        play_a_game();
        count++;
    } while (suitcases[chosen_suitcase - 1] != money[money.size() - 1]);
    cout << "A millionare after " << count << " iteration" << endl;
}

void deal_or_nodeal::play_until_bankrupt(){
    int count = 0;
    do {
        play_a_game();
        count++;
    } while (suitcases[chosen_suitcase - 1] != money[0]);
    cout << "A bankrupt after " << count << " iteration" << endl;
}