#include <iostream>
#include <vector>
#include <string>
#include <map>


class Haltestelle
{

public:
  std::string Name;
  std::vector<std::string> Abfahrtzeiten;
  Haltestelle () = default;
  ~Haltestelle() = default;
  Haltestelle(std::string name, std::vector<std::string> zeiten): Name(name), Abfahrtzeiten(zeiten){
  }

};
class Linie
{
  std::vector<Haltestelle> Haltestellen;

public:
  std::string Name;
  Linie () = default;
  ~Linie() = default;
  Linie(std::string name, std::vector<Haltestelle> haltestellen): Name(name), Haltestellen(haltestellen){
  }
  void DisplayTimetable();
};

void Linie::DisplayTimetable()
{
  std::cout<<"Line Name: "<<this->Name <<std::endl;
  for(auto e : this->Haltestellen)
  {
    std::cout << e.Name << "  ";
    for(auto e2 : e.Abfahrtzeiten)
    {
      std::cout<< e2 << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

class Fahrplan
{
  //stores a map of all possible station routes
  std::map<Linie, std::vector<std::vector<std::string>>> PossibleRoutes;

public:
  std::vector<std::vector<std::string>> GetPossibleRoutes(Linie L);
  void AddPossibleRoutes(Linie L);
};


//std::vector<std::vector<std::string>> Fahrplan::GetPossibleRoutes(Linie L)
//{
//  return PossibleRoutes[L];
//}
//
//void Fahrplan::AddPossibleRoutes(Linie L)
//{
//  if (L.Name == "U1")
//  {
//    PossibleRoutes[L] = {{"Andritz", "Hauptplatz"},{"Andritz", "Hauptplatz", "Goesting"},{"Andritz", "Hauptplatz", "Jako"},{"Andritz", "Hauptplatz","Jako", "Raaba"}, 
//                         {"Andritz", "Hauptplatz","Jako","LKH"}};
//  }
//}




int main()
{
  //U1
  Haltestelle Andritz("Andritz", {"0800","0805","0810"});
  Haltestelle Hauptplatz("Hauptplatz", {"0806","0811","0816"});
  Haltestelle Griesplatz("Griesplatz", {"0809","0814","0819"});
  Haltestelle Liebenau("Liebenau", {"0815","0820","0825"});
  //U2
  Haltestelle LKH("LKH", {"0800","0805","0810"});
  Haltestelle Jako("Jako", {"0806","0811","0816"});
  Haltestelle Griesplatz2("Griesplatz", {"0809","0814","0819"});
  Haltestelle Wetzeldorf("Wetzeldorf", {"0815","0820","0825"});
  //U3  
  Haltestelle Goesting("Goesting", {"0800","0805","0810"});
  Haltestelle Hauptplatz3("Hauptplatz", {"0806","0811","0816"});
  Haltestelle Jako3("Jako", {"0809","0814","0819"});
  Haltestelle Raaba("Raaba", {"0815","0820","0825"});

  //Set Data
  Linie U1("U1", {Andritz, Hauptplatz, Griesplatz, Liebenau});
  Linie U2("U2", {LKH, Jako, Griesplatz2, Wetzeldorf});
  Linie U3("U3", {Goesting, Hauptplatz3, Jako3, Raaba});

  U1.DisplayTimetable();
  U2.DisplayTimetable();
  U3.DisplayTimetable();
}

