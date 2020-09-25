#include <iostream>
#include <fstream>
#include <ctime>


const int MAX_TWEET(97);

void tweetgenerator(std::string arre[], std::string arrk[]){
  int score = 0;
  int outof = 0;
  std::cout << "Do you want to play a game? yes or no" << std::endl;
  std::string yorn;
  std::cin >> yorn;
  int ktweetused[MAX_TWEET] = {};
  int etweetused[MAX_TWEET] = {};
  while(yorn == "yes"){
    int numplace = rand()%98;
    int numarr = rand()%2;
    //account for repeat tweets
    if(numarr == 0){
      int spot = 0;
      for(int i = 0; i < MAX_TWEET; ++i){
        if(etweetused[i] == numplace){
          numplace = rand()%98;
        }
      }
      etweetused[spot] = numplace;
      std::cout << '\n' << arre[numplace] << std::endl;
      std::cout << "is this kanye or elon?" << std::endl;
      std::string answer;
      std::cin >> answer;
      if(answer == "elon" || answer == "Elon"){
        std::cout << "\nGood job" << std::endl;
        score++;
      }else{
        std::cout << "\nactually thats elon :(" << std::endl;
      }
    ++outof;
    std::cout << "Current score " << score << " out of " << outof << std::endl;
    std::cout << "\nDo you want to play again? yes or no" << std::endl;
    std::string yorn;
    std::cin >> yorn;
    if(yorn == "no"){
      std::cout << "Good game see ya later" << std::endl;
      break;
    }
    }else{
      int spot = 0;
      for(int i = 0; i < MAX_TWEET; ++i){
        if(ktweetused[i] == numplace){
          numplace = rand()%98;
        }
      }
      ktweetused[spot] = numplace;
      std::cout << '\n' << arrk[numplace] << std::endl;
      std::cout << "is this kanye or elon?" << std::endl;
      std::string answer;
      std::cin >> answer;
      if(answer == "kanye" || answer == "Kanye"){
        std::cout << "\nGood job" << std::endl;
        score++;
      }else{
        std::cout << "\nactually thats kanye :(" << std::endl;
      }
    ++outof;
    std::cout << "Current score " << score << " out of " << outof << std::endl;
    std::cout << "\nDo you want to play again? yes or no" << std::endl;
    std::string yorn;
    std::cin >> yorn;
    if(yorn == "no"){
      std::cout << "Good game see ya later" << std::endl;
      break;
    }
  }
  }
  
}

int main() {
  srand((size_t)time(NULL));
  std::string elonarr[MAX_TWEET];
  std::string kanyearr[MAX_TWEET];
  std::ifstream infile("elon");
  int i = 0;
  while(getline(infile, elonarr[i])){
    i++;
  }
  std::ifstream infilewest("kanye");
  int j = 0;
  while(getline(infilewest, kanyearr[j])){
    j++;
  }

  tweetgenerator(elonarr, kanyearr);


  
}