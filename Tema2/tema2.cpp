#include<iostream>

class music{
  private:
  int duration=3;
  std::string sound = "LaLaLa";
  
  public:
  music(){
   std::cout<<"A song is created without a parameter"<<std::endl;
  }
  
  music(int duration){
   std::cout<<"A song is created WITH a parameter"<<std::endl;
   this->duration=duration;
  }
  
  music(const music &m){
   std::cout<<"Copy contructor of the song is created!"<<std::endl;
   this->duration=m.duration;
   this->sound=m.sound;
  }
  
  music &operator=(const music &m){
   if(this==&m)
     {
       std::cout<<"Assignment to self!"<<std::endl;
       return *this;
     }
   std::cout<<"Copy assignment operator for music!"<<std::endl;
   this->duration=m.duration;
   this->sound=m.sound;
   return *this;
  }
  
  music &operator+=(const music &m){
   if(this==&m)
     {
       std::cout<<"Assignment to self!"<<std::endl;
       return *this;
     }
   std::cout<<"Copy assignment operator for music!"<<std::endl;
   this->duration+=m.duration;
   this->sound+=m.sound;
   return *this;
  }
  
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
  Pop():music(){
    nr++;
    std::cout<<"This is the constructor of Pop music without parameter"<<std::endl;
  }
  
  Pop(const Pop &p):music(p){
   std::cout<<"Copy contructor of Pop is created!"<<std::endl;
   this->releaseYear=p.releaseYear;
   this->tempo=p.tempo;
   this->theme=p.theme;
  }
  
  Pop &operator=(const Pop &p){
   if(this==&p)
     {
       std::cout<<"Assignment to self!"<<std::endl;
       return *this;
     }
   music::operator=(p);
   std::cout<<"Copy assignment operator for Pop!"<<std::endl;
   this->releaseYear=p.releaseYear;
   this->tempo=p.tempo;
   this->theme=p.theme;
   return *this;
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
  music stay;
  music dynamite;
  music september(5);
  music perfect=september;
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
  
  std::cout<<"   Song September by James Arthur:"<<std::endl;
  september.printDuration();
  september.setDuration(7);
  std::cout<<"UPDATED DURATION: "<<std::endl;
  september.printDuration();
  std::cout<<std::endl;
  perfect=dynamite;
  std::cout<<"   Song Perfect by Ed Sheeran duration:"<<std::endl;
  perfect.printDuration();
  std::cout<<std::endl;
  
  stay=stay;
  std::cout<<std::endl;
  
  home+=dynamite+=stay;
  home.printDuration();
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
  
  hello=hello;
  std::cout<<std::endl;
  
  hello=lover;
  std::cout<<std::endl;
  hello.printDuration();
  
  Pop abc=hello;
}
