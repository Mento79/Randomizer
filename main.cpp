#include <iostream>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;
bool err=false;
vector <vector <string>>uefa{
{"Chelsea" , "Villarreal" , "Bayern" , "Manchester City" , "Atletico de Madrid" , "Inter" , "LOSC Lille" , "Sporting CP"},
{"Real Madrid" , "Barcelona" , "Juventus" , "Manchester United" , "Paris Saint-Germain" , "Liverpool" , "Sevilla" , "Borussia Dortmund"},
{"Porto" , "Ajax" , "Shakhtar Donetsk" , "Leipzig" , "Salzburg" , "Benfica" , "Atalanta" , "Zenit"},
{"Besiktas" , "Dynamo Kyiv" , "Club Brugge" , "Young Boys" , "AC Milan" , "Malmo" , "Wolfsburg" , "Sheriff Tiraspol"}
};
map <string,string>umap;
vector <vector <string>>g(8);


void mapper (){
umap["Manchester City"]="ENG";
umap["Manchester United"]="ENG";
umap["Liverpool"]="ENG";
umap["Chelsea"]="ENG";
umap["Atletico de Madrid"]="ESP";
umap["Real Madrid"]="ESP";
umap["Barcelona"]="ESP";
umap["Villarreal"]="ESP";
umap["Sevilla"]="ESP";
umap["Juventus"]="ITA";
umap["Inter"]="ITA";
umap["Atalanta"]="ITA";
umap["AC Milan"]="ITA";
umap["LOSC Lille"]="FRA";
umap["Paris Saint-Germain"]="FRA";
umap["Ajax"]="NED";
umap["Zenit"]="RUS";
umap["Salzburg"]="AUT";
umap["Leipzig"]="GER";
umap["Bayern"]="GER";
umap["Borussia Dortmund"]="GER";
umap["Wolfsburg"]="GER";
umap["Club Brugge"]="BEL";
umap["Dynamo Kyiv"]="UKR";
umap["Shakhtar Donetsk"]="UKR";
umap["Porto"]="POR";
umap["Sporting CP"]="POR";
umap["Benfica"]="POR";
umap["Besiktas"]="TUR";
umap["Young Boys"]="SUI";
umap["Malmo"]="SWE";
umap["Sheriff Tiraspol"]="MDA";
}


int ran(int s ,int m){
    if (s>m){
        err=true;
        return 0;
    }
    int res = (rand()%(m-s+1))+s;
    return res;

}

void printSeq (vector <int> v){
 //   for (int i=0 , i< v.size();i++){
    for (auto i:v){
        cout << ">>> "<<i << " <<<"<< endl;
    }


}


void ranSeq (int s ,int m , int n , bool x){
    map <int,int> taken;
    vector<int> res;
    int y;
    if (n>m && !x){
            cout << "There aren't enough numbers between the starting and ending numbers";
        exit(0);
        return ;
    }
    if (x){
        while (n--){
            res.push_back(ran(s,m));
        }
    }
    else
        while (n--){
            y=ran(s,m);
            while (taken[y]>0){
                y=ran(s,m);
            }
            taken[y]++;
            res.push_back(y);
        }
    printSeq(res);
}

//vector <string> players;

vector <string> enterPlayers(){
    vector <string> players;
    int n;
    int c=1;
    string x;
    cin >> n;
    while (n--){
        cout << "Enter player "<<c << " Name : ";
        cin >> x;
        players.push_back(x);
        c++;
    }
return players;
}

string ranPlayer (vector <string> players){
    int n=ran(0,players.size()-1);
    return players[n];

}

vector <string> playerSeq (bool x,vector <string> players){
    int n;
    vector <string> v;
    map <int,int> taken;
    for (int i=0 ; i<players.size();i++){
    n=ran(0,players.size()-1);
        while (taken[n]>0){
            n=ran(0,players.size()-1);
        }
        taken [n]++;
        v.push_back(players[n]);
    }
    if (x){
    for (auto i:v){
        cout << i << endl;
    }
    }
    return v;
}


void teams (int n,vector <string> players){
    vector <string> v;
    vector <vector <string>>vv;
    int c=0;
    v=playerSeq(false,players);
    for (int i=0;i<n; i++){
        cout << "Team "<< i+1 <<" : ";
        for (int j=0;(j<ceil((float)v.size()/n))&&(c<v.size());j++){
            cout << v[c] << " - ";
            c++;
        }
        cout << "\n";
    }

}


bool che(int n , string x){
    for (int i=0;i<g[n].size();i++){
        if (umap[x]==umap[g[n][i]]){
        return false;
        }
    }
    return true;
}


void groups() {
    mapper();
    bool flag=false;
    int finshed =0;
    vector <string> v;
    vector <vector <string>>G;
    while (finshed!=4){
        v=playerSeq(false,uefa[finshed]);
        G=g;
        for (int i=0;i<8; i++){
            if (che(i,v[i])){
                flag = true;
                G[i].push_back(v[i]);
            }
            else{
                flag =false;
                break;
            }
        }
        if (flag){
            g=G;
            finshed ++;
        }
    }
}

void grouper(){
    groups();
    for (int i=0 ;i<8 ; i++){
        cout << "Group " << i+1 << " : ";
        for (int j=0 ; j<4 ;j++){
            cout << g[i][j];
            if (j!=3){
                 cout <<" - ";
            }
        }
        cout << "\n";
    }


}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    srand(time(0));
    cout << "Welcome to my randomizer!\nChoose the number of the wanted process\n1.Random number\n2.Random Sequance\n3.Enter List\n4.Uefa Champions League Grouper\n";
    int q,s,e,n,ooo;
    string y;
    vector <string>v;
    do {
    cin >> q;
    switch(q){
        case (1):
            err=false;
            cout << "Enter The Starting number : ";
            cin >> s;
            cout << "Enter The ending number : ";
            cin >> e;
            ooo=ran(s,e);
            if (err){
                    cout << "Starting is greater than ending !";
                break;
            }
            cout << ">>> " << ooo <<" <<<";
            break;

        case (2):
            err=false;
            bool x;
            cout << "Enter The Starting number : ";
            cin >> s;
            cout << "Enter The ending number : ";
            cin >> e;
            cout << "Enter The number of random numbers : ";
            cin >> n;
            cout << "You want a repeated numbers ? (Y/N): ";
            do{
                cin >> y;
                if(y=="y"||y=="Y"){
                    err=false;
                    x=true;
                }
                else if(y=="n"||y=="N"){
                    err=false;
                    x=false;
                }
                else{
                    err=true;
                    cout << "Wrong Input !!!!\n";
                }
            ranSeq(s,e,n,x);
            }
            while(err);
            break;

        case (3):
            err=false;
            cout << "Enter number of players : ";
            v=enterPlayers();
            cout <<"Choose the number of the wanted process\n1.Random Player\n2.Random Sequance\n3.Team builder\n";
            do{
                cin >>n;
                switch(n){
                    case 1 :
                        err=false;
                        cout << ranPlayer(v);
                        break;
                    case 2 :
                        err=false;
                        v =playerSeq(true,v);
                        break;
                    case 3 :
                        err =false ;
                        cout << "enter number of teams : ";
                        cin >> s;
                        teams(s,v);
                        break;
                    default :
                        cout << "Wrong Input !!!!\n";
                        err=true;
                        break;
                }
            }
            while(err);
            break;
        case (4):
            err=false;
            grouper();
            break;

        default :
            cout << "Wrong Input !!!!\n";
            err=true;
            break;
    }
 }
    while(err);



    return 0;
}
