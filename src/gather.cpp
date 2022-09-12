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

// Logic to Gather
vector<int> gather(vector< vector<int> > inputMatrix, vector< vector<int> > indexingMatrix){
    
if(inputMatrix.size() == 0 || indexingMatrix.size() == 0) return {};

vector<int> result(indexingMatrix.size(), 0);

for (int i = 0; i < indexingMatrix.size(); i++) {
  int p = indexingMatrix[i][0];
  int q = indexingMatrix[i][1];
  result[i] = inputMatrix[p][q];
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

// Logic to print an array
void printArray(vector<int> m) {

	vector<int>::iterator inner;
	
  for(int i = 0; i < m.size(); i++){
    cout << inner[i] << " ";
  }
  cout << "\n";
}

// Main Function
int main (int argc, char* argv[]) {
	
	string inputMatrixFile, indexingMatrixFile;
	cout << argv[0];
    
	if (argc < 3) {
        inputMatrixFile = "matrix_input.in";
        indexingMatrixFile = "matrix_input_2.in";
	} else {
        inputMatrixFile = argv[2];
        indexingMatrixFile = argv[2];
	}

  // Read the two files
	vector <vector <int> > inputMatrix = readMatrix(inputMatrixFile);
  vector <vector <int> > indexingMatrix = readMatrix(indexingMatrixFile);
    
  // Print the two matrices
  printMatrix(inputMatrix);
  printMatrix(indexingMatrix);
    
  // gather logic
  parsec_roi_begin();
  vector<int> result = gather(inputMatrix, indexingMatrix);
  parsec_roi_end();
    
  // Print the output matrix
  printArray(result);
    
	return 0;
}
