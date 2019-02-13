
//dictionary encoding

#include <bits/stdc++.h>


using namespace std;

vector<string> WordSpliter(string str)
{

  std::vector<string> WordVec;

  string word = "";

  for (auto x : str)
  {
        if (' '==x || '.'==x ||','==x||'?'==x)
        {

              if(!(""==word))
              {
                  WordVec.push_back(word);
                  word = "";
              }

        }
        else
        {
            word = word + x;

        }
  }

     WordVec.push_back(word);
     return WordVec;

}


vector<int> WordsMapping(vector<string> Words){

    std::vector<int> MappedWords;

  	map<string, int> Wordmap;

    int WordMapId=0;

    for ( unsigned int idx = 0; idx < Words.size(); idx++) {


              if (!Wordmap.count(Words[idx]))
                     Wordmap.insert(make_pair(Words[idx], WordMapId++));

      }


    for (  unsigned int idx = 0; idx < Words.size(); idx++) {

           MappedWords.push_back(Wordmap.find(Words[idx])->second);
    }

  return MappedWords;

}



int main()
{

  string strphase = "The quick brown fox,The quick brown fox fox fox The quick The quick";
  std::vector<string> WordsV=WordSpliter(strphase);
  std::vector<int> MappedWords=WordsMapping(WordsV);

  std::cout << "Mapping of Words " << '\n';

std::cout << "[ ";
  for (size_t i = 0; i < WordsV.size(); i++) {

     std::cout << WordsV[i]<<" ";
  }
  std::cout << "]" << '\n';


  std::cout << "[  ";
    for (size_t i = 0; i < MappedWords.size(); i++) {

       std::cout << MappedWords[i]<<"   ";
    }
    std::cout << "]" << '\n';

  return 0;
}
