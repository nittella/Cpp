#include <iostream>
#include <map>
#include <string>

using namespace std;


int main(){
  int q;
  cin>>q;
  map<string,string> dictionary;
  for (int i=0; i<q; i++){
    string operation;
    cin>>operation;

//    меняем название столицы
    if (operation=="CHANGE_CAPITAL"){
      string country, capital;
      cin>>country>>capital;
      if(dictionary.count(country)==0){
        dictionary[country]=capital;
        cout<<"Introduce new country "<<country<<" with capital "<<capital<<endl;
      } else{
        if (dictionary[country]==capital){
          cout<<"Country "<<country<<" hasn't changed its capital"<<endl;
        } else{
          cout<<"Country "<<country<<" has changed its capital from "<<dictionary[country]<<" to "<<capital<<endl;
          dictionary[country]=capital;
        }
      }
//   меняем название страны
    }else{
      if(operation=="RENAME"){
        string old_country_name, new_country_name;
        cin>>old_country_name>>new_country_name;
        if(old_country_name==new_country_name
        || dictionary.count(old_country_name)==0
        || dictionary.count(new_country_name)!=0){
          cout<<"Incorrect rename, skip"<<endl;
        } else {
          cout<<"Country "<<old_country_name<<" with capital "<<dictionary[old_country_name]<<" has been renamed to "
          <<new_country_name<<endl;
          dictionary[new_country_name]=dictionary[old_country_name];
          dictionary.erase(old_country_name);
        }


      }else{
        if (operation=="ABOUT"){
          string country;
          cin>>country;
          if (dictionary.count(country)==0){
            cout<<"Country "<<country<<" doesn't exist"<<endl;
          } else{
            cout<<"Country "<<country<<" has capital "<<dictionary[country]<<endl;
          }

        } else{
          if(operation=="DUMP"){
            if (dictionary.size()==0){
              cout<<"There are no countries in the world"<<endl;
            } else{
              for (const auto& items : dictionary){
                cout<<items.first<<"/"<<items.second<<" ";
              }
              cout<<endl;
            }

          }
        }
      }
    }
  }
  return 0;
}