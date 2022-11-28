//
// Created by misash on 27/11/22.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

#define ll long long
#define MOD 1000000007

    int rectangleArea(vector<vector<int>>& rectangles) {

        set<int> x,y;
        ll ans = 0;

        for(auto v:rectangles){
            x.insert(v[0]);x.insert(v[2]); // almacenar coordenadas x unicas
            y.insert(v[1]);y.insert(v[3]); // almacenar coordenadas y unicas
        }

        cout<<"\nMAP: ";
        int index = 0;
        unordered_map<int,int> coord_x,coord_y;
        for(auto it:x){
            coord_x[it] = index++; // asignanr todos los x unicos
            cout<<it<<" "<<coord_x[it]<<" ";
        }

        cout<<"\nMAP: ";
        index = 0;
        for(auto it:y){
            coord_y[it] = index++; // asignanr todos los y unicos
            cout<<it<<" "<<coord_x[it]<<" ";
        }

        //almacenar coordenadas
        vector<int> x_val(x.begin(),x.end());
        vector<int> y_val(y.begin(),y.end());

        cout<<"\ncoordenadas x:";
        for ( auto xs : x_val) {
            cout<<xs<<" ";
        }
        cout<<"\ncoordenadas y:";
        for ( auto xs : x_val) {
            cout<<xs<<" ";
        }

        vector<vector<bool>> visited(x.size(),vector<bool>(y.size(),false));
        cout<<"\nVisited :\n";
        for ( auto status : visited) {
            for (auto st : status) {
                cout<<st<<" ";
            }
            cout<<"\n";
        }

        for(auto v:rectangles)
        {
            for(auto start_x=coord_x[v[0]];start_x<coord_x[v[2]];start_x++)
            {
                for(auto start_y=coord_y[v[1]];start_y<coord_y[v[3]];start_y++)
                {

                    if(!visited[start_x][start_y])
                    {
                        ll width = x_val[start_x+1] - x_val[start_x];
                        ll height = y_val[start_y+1] - y_val[start_y];;
                        ans = (ans + (width*height)%MOD)%MOD;
                    }

                    visited[start_x][start_y] = true;
                }
            }
        }

        cout<<"\n";
        return ans;

    }
};


int main(){
    Solution s;

    vector<vector<int>> r = {{0,0,2,2},{1,0,2,3},{1,0,3,1}};

    cout<<s.rectangleArea(r);


}