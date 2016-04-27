#include <EulerRunner.h>
#include <EulerShared.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

class EulerMaxPath : public EulerQuestion {
private:
  std::vector<std::vector<int>> trianglePath;
  std::string filepath;
  int id;

public:
  EulerMaxPath(std::string name, int id, std::string filePath)
      : EulerQuestion(name, id), filepath(filePath), id(id) {}

  int max(int a, int b) { return (a > b) ? a : b; }

  void loadFile(std::string file) {
    std::ifstream fs(filepath);
    char cline[1024];
    fs.getline(cline, 1024);
    while (!fs.eof()) {
      std::vector<int> tmp;
      char *tok = strtok(cline, " ");
      while (tok != NULL) {
        tmp.push_back(atoi(tok));
        tok = strtok(NULL, " ");
      }
      trianglePath.push_back(tmp);
      fs.getline(cline, 1024);
    }
  }
  void calculatePaths() {
    std::vector<vector<int>>::iterator prevRow = trianglePath.begin();
    for (std::vector<vector<int>>::iterator rowIter = trianglePath.begin();
         rowIter != trianglePath.end(); rowIter++, prevRow++) {
      if (rowIter == trianglePath.begin())
        rowIter++;
      for (int i = 0; i < rowIter->size(); i++) {
        if (i == 0) {
          (*rowIter)[i] += (*prevRow)[i];
        } else if (i == rowIter->size() - 1) {
          (*rowIter)[i] += (*prevRow)[i - 1];
        } else {
          (*rowIter)[i] += max((*prevRow)[i], (*prevRow)[i - 1]);
        }
      }
    }
  }
  void QuestionFunc() {
    loadFile(filepath);
    calculatePaths();
    std::vector<int> finalRow = trianglePath.back();
    int currMax = 0;
    for (int i = 0; i < finalRow.size(); i++) {
      currMax = max(currMax, finalRow[i]);
    }
    std::cout << "Problem " << id << " answer: " << currMax << endl;
  }
};

class Euler018 : public EulerMaxPath {
public:
  Euler018(std::string name, int id)
      : EulerMaxPath(name, id, "res/Euler018.txt") {}
};

class Euler067 : public EulerMaxPath {
public:
  Euler067(std::string name, int id)
      : EulerMaxPath(name, id, "res/Euler067.txt") {}
};

REGISTER_TEST("Problem 18: Maximum path sum I", 18, Euler018);
REGISTER_TEST("Problem 67: Maximum path sum II", 67, Euler067);
