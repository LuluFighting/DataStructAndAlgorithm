//
// Created by Admin on 2019/10/28.
//
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct LinkNode{
    int index;
    LinkNode *next;
    LinkNode(int val):index(val),next(NULL) {}
};

class Graph{
public:
    Graph(int num):n(num){
        if(n!=0) vertex = new (LinkNode*)[num];
    }
    bool BFS(int target){
        if( 0 == n) return;
        int visited[n] = {0};
        for(int i=0;i<n;++i){
            if(visited[i]==0 &&  bfs(i,target,visited) == true)
                return true;
        }
        return false;
    }
    bool DFS(int target){
        if( 0 == n )return;
        int visited[n] = {0};
        int *prev = new int[n](-1);
        for(int i=0;i<n;++i){
            if(visited[i]==0 && dfs(i,target,visited,prev) == true){
                return true;
            }
        }
        return false;
    }
private:
    bool dfs(int s,int t,int *visited,int *prev){
        visited[s] = 1;
        if(s == t){
            print(prev,s,t);
            return true;
        }
        LinkNode* pcur = vertex[s];
        while(pcur){
            if(visited[pcur->index]==0){
                prev[pcur->index] = s;
                if(true == dfs(pcur->index,t,visited,prev)) return true;
            }
            pcur = pcur->next;
        }
        return false;
    }
    void print(int *prev,int s,int t){
        if(s!=t && prev[t]!=-1){
            print(prev,s,prev[t]);
        }
        cout << t << " ";
    }
    bool bfs(int start,int target,int visited){
        if(start == target) return true;
        queue<LinkNode*> myQueue;
        visited[start] = 1;
        int *prev = new int[n](-1);
        myQueue.push(vertex[start]);
        while(!myQueue.empty()){
            LinkNode* pcur = myQueue.front();
            int cur_index = pcur->index;
            myQueue.pop();
            while(pcur){
                if(visited[pcur->index]==0){
                    prev[pcur->index] = cur_index;
                    if(pcur->index == target){
                        print(prev,start,target);
                        return true;
                    }
                    visited[pcur->index] = 1;
                    myQueue.push(pcur);
                }
                pcur = pcur->next;
            }
        }
        return false;
    }
    int n;
    (LinkNode*)* vertex;
};
