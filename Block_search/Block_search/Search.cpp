#include "Search.h"

using namespace std;

search::search() {
	ifstream ifs;
	string cmd;
	cout << "Please input the sorted array of numbers you wish to search from:\n";
//可以考虑可以手动输入
	cin >> cmd;
	cmd = parse_path(cmd);
	ifs.open(cmd);
	if(!ifs) {
		throw runtime_error("search::search(): cannot open specified file!");
	}
	string block;
	size_t line{0};
	size_t array{0};
	int temp;
	while(!ifs.eof()) {
		getline(ifs, block);
		if (block == "") {
			break;
		}
		line++;
		istringstream iss(block);
		while(iss>>temp) {
			array++;
		}
	}
	ifs.seekg(ios_base::beg);
	data = new int[array];
	index = new index_block[line];
	block_num = line;
	line = 0;
	array = 0;
	while (!ifs.eof()) {
		getline(ifs, block);
		if (block == "") {
			break;
		}
		index[line].data = data;
		index[line].bock_size = 0;
		index[line].start = array;
		istringstream iss(block);
		while (iss >> temp) {
//			index[line][index[line].bock_size] = temp;
			data[array] = temp;
			index[line].bock_size++;
			array++;
		}
		line++;
	}
}

search::~search() {
	delete[] data;
	delete[] index;
}
