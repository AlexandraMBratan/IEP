#include<iostream>

class music{
  private:
  int duration=3;
  std::string sound = "LaLaLa";
  
  public:
  music(){
   std::cout<<"A song is created"<<std::endl;
  }
  
  music(const music &m)=delete;
  
  music &operator=(const music &m)=delete;
  
  int printDuration(){
   std::cout<<"Duration: "<<duration<<std::endl;
   return this->duration;
  }
  
  std::string printSound(){
    std::cout<<"Sound= "<<sound<<std::endl;
    return this->sound;
  }
  
  void setDuration(int duration){
    this->duration=duration;
  }  
  
  void setSound(std::string sound){
    this->sound=sound;
  }
  
  virtual ~music(){
    std::cout<<"The song finished"<<std::endl;
  }

};

class Pop : public music{
  private:
  int releaseYear=2017;
  std::string tempo="alegro";
  std::string theme="love";
  static int nr;
  
  public:
  Pop(){
    nr++;
    std::cout<<"This is the constructor of Pop music"<<std::endl;
  }
  
  int printReleaseYear(){
    std::cout<<"The release year of this song is: "<<releaseYear<<std::endl;
    return this->releaseYear;
  }
  
  std::string printTempo(){
    std::cout<<"The tempo of this song is: "<<tempo<<std::endl;
    return this->tempo;
  }
  
  std::string printTheme(){
    std::cout<<"The theme of this song is: "<<theme<<std::endl;
    return this->theme;
  }
  
  void setReleaseYear(int releaseYear){
   this->releaseYear=releaseYear;
  }
  
  void setTempo(std::string tempo){
    this->tempo=tempo;
  }
  
  void setTheme(std::string theme){
    this->theme=theme;
  }
  
  ~Pop(){
   std::cout<<"This is the Pop music destructor!"<<std::endl;
  } 

};

int Pop::nr=0;


int main(){
  music perfect;
  music dynamite;
  music september;
  music stay;
  music home;
  std::cout<<std::endl;
  
  std::cout<<"   Song Perfect by Ed Sheeran:"<<std::endl;
  perfect.printDuration();
  perfect.printSound();
  std::cout<<std::endl;
  
  std::cout<<"   Song Stay by Rihanna:"<<std::endl;
  stay.printDuration();
  stay.printSound();
  stay.setDuration(5);
  std::cout<<"UPDATED DURATION: "<<std::endl;
  stay.printDuration();
  std::cout<<std::endl;
  
  std::cout<<"   Song Dynamite by BTS:"<<std::endl;
  dynamite.setDuration(4);
  dynamite.printSound();
  dynamite.setSound("NaNaNa");
  dynamite.printDuration();
  std::cout<<"UPDATED SOUND:"<<std::endl;
  dynamite.printSound();
  std::cout<<std::endl;
  
  Pop lover;
  Pop hello;
  
  std::cout<<"   Song LOver by Taylor Swift:"<<std::endl;
  lover.printTempo();
  lover.printTheme();
  lover.printReleaseYear();
  std::cout<<std::endl;
    
  std::cout<<"   Song Hello by Adele:"<<std::endl;
  hello.setTheme("Breakup");
  hello.setTempo("Adagio");
  hello.setReleaseYear(2015);
  hello.printTheme();
  hello.printTempo();
  hello.printReleaseYear();
  std::cout<<std::endl;
  
}
