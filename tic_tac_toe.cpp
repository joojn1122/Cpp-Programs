#include <iostream>
#include <istream>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

class Game{
public:
	int player;
	set<int> used;
	int current;
	string map[9] = {"1","2","3","4","5","6","7","8","9"};

	void update(){
		cout << "+-----+" << endl;
		for(int i=0;i<sizeof(map)/sizeof(map[0]);i+=3){
			cout << "|";
			cout << map[i] + "|" + map[i+1] + "|" + map[i+2];
			cout << "|" <<endl;
			if(i < 6){cout << "|-----|" << endl;};
		};
		cout << "+-----+" << endl;
	};
	void play(){
		string input;

		while(1){
			if(player == 1){cout << "Player X: " << endl;}
			else{cout << "Player O: " << endl;};

			cin >> input;
			try{
				int intInput = stoi(input);
				if(intInput > 0 && intInput < 10){
					bool found = (find(used.begin(), used.end(), intInput) != used.end());
					if(found){
						update();
						cout << "Slot already used please select different one!" << endl;
					}else{
						addValue(intInput);
						used.insert(intInput);
						break;
					};
				}else{
					update();
					cout << "Number must be between 1-9!" << endl;
				};
			}catch(exception e){
				update();
				cout << "Invalid number!" << endl;
			};
			
		};
	};
	void addValue(int value){
		if(player == 1){
			map[value-1] = "X";
		}else{
			map[value-1] = "O";
		};
	};
	bool test(){
		int win[8][3] = {{1,2,3},
						{4,5,6},
						{7,8,9},
						{1,4,7},
						{2,5,8},
						{3,6,9},
						{1,5,9},
						{3,6,7}};
		for(int i=0;i<sizeof(win)/sizeof(win[0]);i++){
			int* con = win[i];
			int x = con[0] - 1;
			int y = con[1] - 1;
			int z = con[2] - 1;
			if(map[x] == "X" && map[y] == "X" && map[z] == "X"){
				cout << "Player X won the game!" << endl;
				return true;
			}else if(map[x] == "O" && map[y] == "O" && map[z] == "O"){
				cout << "Player O won the game!" << endl;
				return true;
			};
		};
	return false;	
	};
};


int main() 
{
	while(1){
	    Game game;	
	    game.player = rand() % 2;
	    game.update();

	    while(1){
	    	game.play();
	    	game.update();
	    	if(game.player == 1){game.player = 2;}
	    	else{game.player = 1;};
	    	if(game.test()){break;};
	    };
	    string yn;
	    cout << "Do you want to play again? [y/n]" << endl;
	    cin >> yn;
	    if(!(yn == "Y" || yn == "y")){break;};
    }
    return 0;
}
