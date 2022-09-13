#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

std::vector<vector<int> > gv{
      {1, 2, 2},
      {0, 0, 0},
      {3, 3, 3}
};

void parsec_roi_begin() 
{

}

void parsec_roi_end() 
{

}

// The below function holds logic to read matrix
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

vector <int> readArray(string filename){

  vector <int> result;
  string line;
  ifstream infile;
  infile.open(filename.c_str());
  int i = 0;

  if(getline(infile, line)){
    istringstream iss(line);
    int n;
    while(iss >> n){
      result.push_back(n);
    }  
  }
  return result;

}

// Logic to SCATTER
void scatter(vector<int> dataValueMatrix, vector< vector<int> > indexingMatrix){
    
if (dataValueMatrix.size() == indexingMatrix.size())
{
  for (int i = 0; i < indexingMatrix.size(); i++) {
    int p = indexingMatrix[i][0];
    int q = indexingMatrix[i][1];
    gv[p][q] = dataValueMatrix[i];
  }
}
}

// Below function holds the logic to print a matrix
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
	
	string indexingMatrixFile;
	cout << argv[0];
    
	if (argc < 3) {
        //inputMatrixFile = "matrix_input_scatter.in";
        indexingMatrixFile = "matrix_indexing_scatter.in";
	} else {
        //inputMatrixFile = argv[2];
        indexingMatrixFile = argv[2];
	}

  // Reading the two files
  vector <int> inputMatrix {5, 9};
  vector <vector <int> > indexingMatrix = readMatrix(indexingMatrixFile);
    
  // scatter logic
  parsec_roi_begin();
	scatter(inputMatrix, indexingMatrix);
  parsec_roi_end();
    
  // printing the output matrix
  for (int i = 0; i < gv.size(); i++) {
			for (int j = 0; j < gv[0].size(); j++) {
        cout << gv[i][j] << " ";
			}
      cout << '\n';
	}
    
	return 0;
}
