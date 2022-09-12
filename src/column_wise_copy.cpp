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

// The below function holds logic to read a matrix
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

// Logic to copy a given matrix column-wise
vector <vector<int> > columnWiseCopyOfAMatrix(vector< vector<int> > m){

  if(m.size() == 0) return {};

  vector <int> a(m.size(), 0);
  vector <vector <int> > result(m[0].size(), a);

	for(int j = 0; j < m[0].size(); j++){
	  for(int i = 0; i < m.size(); i++){
			result[i][j] = m[j][i];
		}
	}
	return result;
}

// Below function holds the logic to print a matrix
void printResultantMatrix(vector< vector<int> > m) {

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
        file = "columncopy_input.in";
	} else {
        file = argv[2];
	}

  // Reading the file
	vector <vector <int> > matrix = readMatrix(file);
    
  // printing the input matrix
  printResultantMatrix(matrix);
    
  // Columnwise Copy logic
  parsec_roi_begin();
  vector< vector<int> > result = columnWiseCopyOfAMatrix(matrix);
  parsec_roi_end();
  
  // printing the output matrix
  printResultantMatrix(result);
    
	return 0;
}
