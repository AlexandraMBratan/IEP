#include<iostream>
#include<memory>

class music{
  private:
  int duration=3;
  std::string sound = "LaLaLa";
  bool isLocked = false;
  
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
   this->isLocked=m.isLocked;
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
   this->isLocked=m.isLocked;
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
  
  bool printLocked(){
   std::cout<<"Locked: "<<isLocked<<std::endl;
   return this->isLocked;
  }
  
  void setDuration(int duration){
    this->duration=duration;
  }  
  
  void setSound(std::string sound){
    this->sound=sound;
  }
  
  void setLocked(bool isLocked){
    this->isLocked=isLocked;
  }  
  
  void lockedOrNot(){
    if(this->isLocked == true) {
     std::cout<<"Melodia este blocata. Nu poate fi redata!"<<std::endl;
    }else{
      std::cout<<"Melodia poate fi redata!"<<std::endl;
    }  
  }
  
  virtual ~music(){
    std::cout<<"The song finished"<<std::endl;
  }

};


void lock(music &m){
  std::cout<<"Melodia este blocata"<<std::endl;
  m.setLocked(true);
}

void unlock(music &m){
  std::cout<<"Melodia NU este blocata"<<std::endl;
  m.setLocked(false);
}

class Lock {
 private:
  music &musicPtr;
  
 public:
  Lock(music &mptr):
   musicPtr(mptr){
    lock(musicPtr);
  }
  
  ~Lock(){
   unlock(musicPtr);
  }
};


using namespace std;
music* createMusic(){
 return(new music);
}

int main(){
  std::cout<<"   Folosind auto_ptr:"<<std::endl;
  { 
    auto_ptr<music> hello(createMusic());
    hello->printDuration();
    hello->printSound();
    hello->setDuration(5);
    hello->printDuration();
    
    auto_ptr<music> fire(hello);
   // hello->printDuration();
    fire->printDuration();
    
  }
  std::cout<<std::endl;
  
  std::cout<<"   Folosind unique_ptr:"<<std::endl;
  { 
    unique_ptr<music> dynamite(createMusic());
    dynamite->printDuration();
    dynamite->setDuration(10);
    dynamite->printDuration();
    dynamite->setSound("NaNaNa");
    
    //unique_ptr<music> stay(dynamite);
    //stay->printSound();
    
    unique_ptr<music> stay= move(dynamite);
    stay->printSound();
    stay->printDuration();
    
    //dynamite->printSound();
  }
  std::cout<<std::endl;
  
  std::cout<<"   Folosind shared_ptr:"<<std::endl;
  {
    shared_ptr<music> september(createMusic());
    september->printSound();
    september->printDuration();
    std::cout<<"Count: "<<september.use_count()<<std::endl;
    
    shared_ptr<music> home=move(september);
    std::cout<<"Count: "<<september.use_count()<<std::endl;
    std::cout<<"Count: "<<home.use_count()<<std::endl;
    home->printSound();
   // september->printDuration();
    
    shared_ptr<music>  perfect(home);
    perfect->setSound("DuDuDu");
    home->printSound();
    std::cout<<"Count: "<<perfect.use_count()<<std::endl;
  }
  std::cout<<std::endl;
  
  music rain(7);
  Lock *lockMusic = new Lock(rain);
  rain.lockedOrNot();
  delete lockMusic;
  rain.lockedOrNot();
}
