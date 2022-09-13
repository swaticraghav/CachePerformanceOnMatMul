#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void parsec_roi_begin() 
{

}

void parsec_roi_end() 
{

}

// Logic to read matrix
vector <vector <int> > readMatrix(string inputFile){
    
	vector <vector <int> > result;
	string line;
	ifstream infile;
    
	infile.open(inputFile.c_str());
    
	int i = 0;
    while (getline(infile, line) && !line.empty()) {
			istringstream iss(line);
            result.resize(result.size() + 1);
			int a, j = 0;
			while (iss >> a) {
                result[i].push_back(a);
				j++;
			}
			i++;
		}
	infile.close();
	return result;

}

// Logic to transpose a given matrix
vector <vector<int> > transposeMatrix(vector< vector<int> > m){
    
    if(m.size() == 0) return {};
    
    vector <int> a(m.size(), 0);
    vector <vector <int> > result(m[0].size(), a);

	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m[i].size(); j++){
			result[i][j] = m[j][i];
		}
	}

	return result;
}

// Logic to print a matrix
void printMatrix(vector< vector<int> > m) {

	vector< vector<int> >::iterator it;
	vector<int>::iterator inner;

	for (it=m.begin(); it != m.end(); it++) {
		for (inner = it->begin(); inner != it->end(); inner++) {
			cout << *inner;
			if(inner+1 != it->end()) {
				cout << "\t";
			}
		}
		cout << endl;
	}
}

// Main Function
int main (int argc, char* argv[]) {
	
	string file;
	cout << argv[0];
    
	if (argc < 3) {
        file = "matrix_input_transpose.in";
	} else {
        file = argv[2];
	}

    // Read the file
	vector <vector <int> > matrix = readMatrix(file);
    
    // print the input matrix
	cout << "Input Matrix - ";
    printMatrix(matrix);
    
    // transpose logic
    parsec_roi_begin();
	vector< vector<int> > matrix_transpose = transposeMatrix(matrix);
    parsec_roi_end();
    
    // print the output matrix
	cout << "Transpose Matrix - ";
    printMatrix(matrix_transpose);
    
	return 0;
}
