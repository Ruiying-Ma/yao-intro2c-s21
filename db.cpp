#include <cstring>
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <memory.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <functional>
#include <ctime>
#include <set>
#include <mutex>
#include <time.h>
#include <thread>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//#define INT_MAX 2147483647
int timestamp=0;


/*class DataStorage{
    //不同类型存储节点
    //num 为存储节点中数据个数
    //max_path为存储节点二叉树最长路径长度
    protected:
    int num;
    int max_path;
    
    public:
        DataStorage(){
            }
        virtual void insert(int key, int value)=0;
        virtual string query(int key)=0;
        virtual void update(int key, int valye)=0;
        virtual void GetNode()=0;
        
};*/

class Array {
    vector<pair<int,string> > MyArray;
    public:
        pair<int,string> Get_item(int x){
            return MyArray[x];
        }
        int Array_Size(){
            return MyArray.size();
        }
        void insert(int key, int value){
        //插入数组元素（存储节点）
          MyArray.push_back(make_pair(key, to_string(value)));
        }
        string query(int key){
        //访问数组元素 （存储节点），返回value
          vector<pair<int,string> > ::iterator array_iter;
          for(array_iter = MyArray.begin(); array_iter != MyArray.end(); array_iter++){
            if(array_iter->first == key){
              return array_iter->second;
            }
          }
          return "NOT FOUND";
        }
        void update(int key, int value){
        //更新数组元素 （存储节点）
          vector<pair<int,string> > ::iterator array_iter;
          for(array_iter = MyArray.begin(); array_iter != MyArray.end(); array_iter++){
            if(array_iter->first == key);
            array_iter->second = to_string(value);
            return;
          }
        }
        void GetNode(){
        //输出Array\n,输出key key key 
          cout<<"Array\n";
          vector<pair<int,string> > ::iterator array_iter;
          for(array_iter = MyArray.begin(); array_iter != MyArray.end(); array_iter++){
            cout<<array_iter->first<<" ";
          }
          cout<<"\n";
          return;  
        }
        
};

struct BinaryTreeNode
{
    int key;
    int value;
    BinaryTreeNode *pLeft;
    BinaryTreeNode *pRight;
};

BinaryTreeNode*createNode(int key,int value)
{
    BinaryTreeNode*n = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    n -> key = key;
    n -> value = value;
    n -> pLeft = NULL;
    n -> pRight = NULL;
    return n;
}

class BinarySearchTree {
    int num;
    int max_path;
    BinaryTreeNode*root;
    public:
        BinarySearchTree(){root=NULL; num = 0; max_path =0;}
        BinaryTreeNode* GetRoot(){return root;}
        int GetNum(){return num;}/////////////////////////////
        int GetPath(){return max_path;}////////////////////////////////////
        bool ChangeStruct(){
            if ( (6*max_path) >= num){
                return true;
            }
            return false;
        }
        void Update_Struct(Array* ptr_array){
	    //数组转化为二叉树
         /* root = createNode(ptr_array->Get_item(0).first, stoi(ptr_array->Get_item(0).second));   
	      for(int i=1; i<ptr_array->Array_Size(); i++){
            pair<int, string> cur_array_item = ptr_array->Get_item(i);
            BinaryTreeNode* traverse_ptr = root;
            bool flag = false;
            while( flag == false){
              if(cur_array_item.first <= traverse_ptr->key){
                if(traverse_ptr->pLeft != nullptr){
                    traverse_ptr = traverse_ptr->pLeft;
                }
                else{
                    flag = true;
                }
              }
              else{
                if(traverse_ptr->pRight != nullptr){
                    traverse_ptr = traverse_ptr->pRight;
                }
                else{
                    flag = true;
                }
              }
            }
            if(cur_array_item.first <= traverse_ptr->key){
                traverse_ptr->pLeft = createNode(cur_array_item.first, stoi(cur_array_item.second));
            }
            else{
                traverse_ptr->pRight = createNode(cur_array_item.first, stoi(cur_array_item.second));
            }   	
         }*/
          for(int i=0; i<64; i++){
              pair<int, string> cur_item = ptr_array->Get_item(i);
              insert(cur_item.first, stoi(cur_item.second));
          }
          return;


        }

        void insert(int key, int value){   
            //插入树节点
            //this function is uncomplete!!!!!
            int cur_path_len =1;
            if (root == NULL) {
                root = createNode(key,value); 
                max_path +=1;
                num +=1;
                
            } 
            else {
                BinaryTreeNode* current = root; 
                while (1) {
                    if (key >= current -> key) { 
                        if (current -> pRight != NULL) {
                            cur_path_len +=1;
                            current = current -> pRight; 
                        }
                        else{
                            current -> pRight = createNode(key,value);
                            num+=1; 
                            cur_path_len +=1;
                            break; 
                        }
                    }
                    else { 
                        if (current -> pLeft != NULL) {
                            cur_path_len +=1;
                            current = current -> pLeft; 
                        }
                        else{
                            cur_path_len +=1;
                            current -> pLeft = createNode(key,value);
                            num+=1; 
                            break; 
                        }
                    }
                }
                
            }
            //更新最长路径长度（存储节点）
            if(cur_path_len > max_path){
                max_path = cur_path_len;
            }
            //更新数据个数（存储节点）
            return;
        }
        BinaryTreeNode*findNode(int n){   
            //根据key找节点，返回节点指针
            BinaryTreeNode*current = root; 
            while (current != NULL) 
            {
                if (n > current -> key) current = current -> pRight; 
                else if (n < current -> key) current = current -> pLeft; 
                else return current; 
            }
            return NULL; 
        }

        string query(int key){
        //查询key是否存在（存储节点），返回value （string） 
          BinaryTreeNode* target_node = findNode(key);
          if(target_node != nullptr){
            return to_string(target_node-> value);
          }
          return "NOT FOUND"; 
        }

        void update(int key, int value){
        //更新树的某个节点（存储节点）
            BinaryTreeNode* target_node = findNode(key);
            if(target_node != nullptr){
                target_node->value = value;
                return;
            }
            return;
        }
        void levels_showBT(){
	    //层序输出二叉树 
        queue<BinaryTreeNode*> layer;
          layer.push(root);
          while(!layer.empty()){
              BinaryTreeNode* head = layer.front();
              if(head->pLeft != nullptr){
                  layer.push(head->pLeft);
              }
              if(head->pRight != nullptr){
                  layer.push(head->pRight);
              }
              cout<<head->key<<" ";
              layer.pop();
          }
          cout<<"\n";
        }
        void levels_showBT_FirstChild(){
	    //层序输出二叉树是否是第一个孩子
        queue<BinaryTreeNode*> layer;
        queue<bool> IsFrstChild;
          layer.push(root);
          IsFrstChild.push(0);
          while(!layer.empty()){
              BinaryTreeNode* head = layer.front();
              if(head->pLeft != nullptr){
                  layer.push(head->pLeft);
                  IsFrstChild.push(1);
              }
              if(head->pRight != nullptr){
                  layer.push(head->pRight);
                  if(head->pLeft != nullptr){
                      IsFrstChild.push(0);
                  }
                  else{
                      IsFrstChild.push(1);
                  }
              }
              cout<<IsFrstChild.front()<<" ";
              layer.pop();
              IsFrstChild.pop();
          }
          cout<<"\n";   
        }
        void levels_showBT_IsLeaf(){
	    //层序输出二叉树是否是叶子
          queue<BinaryTreeNode*> layer;
          queue<bool> IsLeaf;
          layer.push(root);
          IsLeaf.push(0);
          while(!layer.empty()){
              BinaryTreeNode* head = layer.front();
              if(head->pLeft != nullptr){
                  layer.push(head->pLeft);
                  if((head->pLeft)->pLeft == nullptr && ((head->pLeft)->pRight) == nullptr){
                      IsLeaf.push(1);
                  }
                  else{
                      IsLeaf.push(0);
                  }
              }
              if(head->pRight != nullptr){
                  layer.push(head->pRight);
                  if((head->pRight)->pLeft == nullptr && ((head->pRight)->pRight) == nullptr){
                      IsLeaf.push(1);
                  }
                  else{
                      IsLeaf.push(0);
                  }
              }
              cout<<IsLeaf.front()<<" ";
              layer.pop();
              IsLeaf.pop();
          }
          cout<<"\n";     
        }
        void GetNode(){
            cout<<"Binary Search Tree"<<endl;
            levels_showBT();
            levels_showBT_FirstChild();
            levels_showBT_IsLeaf();
        }
    //释放二叉树内存
    
};



string Int2BiString(int key){
    //将key转化为32位二进制字符串
    string a="";
    for(int i=0;i<32;++i){
        a=to_string((key>>i)%2)+a;
    }
    return a;
}

struct TrieNode{
    TrieNode* next[2];
    bool isword;
    int value;
    TrieNode(bool ISWORD, int VALUE){
        memset(next,0,sizeof(next));
        isword=ISWORD;
        value=VALUE;
    }
    ~TrieNode(){
        for(int i=0;i<2;i++)if(next[i])delete next[i];
    }
};

class BinaryTrie {
    TrieNode*root;
    public:
        BinaryTrie(){
        root=new TrieNode(false, 0);
        }
        ~BinaryTrie(){
        delete root;
        }
        void Update_Struct(BinarySearchTree* ptr_bst){
            queue<BinaryTreeNode*> bst_node_queue;
            bst_node_queue.push(ptr_bst->GetRoot());
            while(!bst_node_queue.empty()){
                BinaryTreeNode* cur_node = bst_node_queue.front();
                if(cur_node->pLeft != nullptr){
                    bst_node_queue.push(cur_node->pLeft);
                }
                if(cur_node->pRight != nullptr){
                    bst_node_queue.push(cur_node->pRight);
                }
                insert(cur_node->key, cur_node->value);
                bst_node_queue.pop();
            }
            return;

        };
        void insert(int key,int value) {
        //插入trie树元素（存储节点），根据key值 
          if(root == nullptr){
              root = new TrieNode(false, 0);
          }
          string key_bin = Int2BiString(key);
          TrieNode* cur_trie_ptr = root;
          for(int i=0; i<32; i++){
            
             if(key_bin[i] == '0'){
               if(cur_trie_ptr->next[0] == nullptr){
                   TrieNode* newtrienode;
                   if( i!= 31){
                     newtrienode = new TrieNode(false, 0);
                   }
                   else{
                     newtrienode = new TrieNode(true, value); 
                   }
                   cur_trie_ptr->next[0] = newtrienode;
               }
               cur_trie_ptr = cur_trie_ptr->next[0];
             }
             else{
                if(cur_trie_ptr->next[1] == nullptr){
                   TrieNode* newtrienode; 
                   if( i!= 31){
                     newtrienode = new TrieNode(false, 0);
                   }
                   else{
                     newtrienode = new TrieNode(true, value); 
                   }
                   cur_trie_ptr->next[1] = newtrienode;
                }
                cur_trie_ptr = cur_trie_ptr->next[1];
             }
            
          }
          return;

        }
        TrieNode*findNode(int key){
        //找key所在的树节点（存储节点）
         string key_bin = Int2BiString(key);
         TrieNode* cur_trie_ptr = root;
         for(int i=0; i<32; i++){
            if(key_bin[i] == '0'){
                if(cur_trie_ptr->next[0] != nullptr){
                    cur_trie_ptr = cur_trie_ptr->next[0];
                }
                else{
                    return nullptr;
                }
            }
            else{
                if(cur_trie_ptr->next[1] != nullptr){
                    cur_trie_ptr = cur_trie_ptr->next[1];
                }
                else{
                    return nullptr;
                }

            }

         } 
         return cur_trie_ptr;
        }

        string query(int key){
        //查找key，输出value  （string）
          TrieNode* result = findNode(key);
          if(result == nullptr){
              return "NOT FOUND";
          }
          return to_string(result->value);
        }
        void update(int key, int value){
        //更新树节点(节点已存在)
           TrieNode* result = findNode(key);
           result->value = value;  
        }
        void levels_showTrie(){
	    //层序输出树节点 
          queue<TrieNode*> layer;
          queue<bool> bin;
          layer.push(root);
          bin.push(0);
          while(!layer.empty()) {
              TrieNode* head = layer.front();
              if(head->next[0] != nullptr){
                  layer.push(head->next[0]);
                  bin.push(0);
              }
              if(head->next[1] != nullptr){
                  layer.push(head->next[1]);
                  bin.push(1);
              }
              if(head != root){
                  cout<< bin.front()<<" ";
              }
              layer.pop();
              bin.pop(); 
          }
          cout<<"\n";
        }
        void levels_showTrie_FirstChild(){
	    //层序输出是否是第一个孩子 
          queue<TrieNode*> layer;
          queue<bool> IsFirstChild;
          layer.push(root);
          IsFirstChild.push(0);
          while(!layer.empty()) {
              TrieNode* head = layer.front();
              if(head->next[0] != nullptr){
                  layer.push(head->next[0]);
                  IsFirstChild.push(1);
              }
              if(head->next[1] != nullptr){
                  layer.push(head->next[1]);
                  if(head->next[0] == nullptr){
                      IsFirstChild.push(1);
                  }
                  else{
                      IsFirstChild.push(0);
                  }
              }
              if(head != root){
                  cout<< IsFirstChild.front()<<" ";
              }
              layer.pop();
              IsFirstChild.pop(); 
          }
          cout<<"\n";  
        }
        void levels_showTrie_IsLeaf(){
	    //层序输出是否是叶子结点
          queue<TrieNode*> layer;
          queue<bool> IsLeaf;
          layer.push(root);
          IsLeaf.push(0);
          while(!layer.empty()) {
              TrieNode* head = layer.front();
              if(head->next[0] != nullptr){
                  layer.push(head->next[0]);
                  if((head->next[0])->next[0] == nullptr && (head->next[0])->next[1] == nullptr){
                      IsLeaf.push(1);
                  }
                  else{
                      IsLeaf.push(0);
                  }
              }
              if(head->next[1] != nullptr){
                  layer.push(head->next[1]);
                  if((head->next[1])->next[0] == nullptr && (head->next[1])->next[1] == nullptr){
                      IsLeaf.push(1);
                  }
                  else{
                      IsLeaf.push(0);
                  }
              }
              if(head != root){
                  cout<< IsLeaf.front()<<" ";
              }
              layer.pop();
              IsLeaf.pop(); 
          }
          cout<<"\n";   
        }
        
        void GetNode(){
            cout<<"Trie"<<endl;
            levels_showTrie();
            levels_showTrie_FirstChild();
            levels_showTrie_IsLeaf();
        }
};




class DataNode{
    //真正存储节点（n个）
    int Nodeid;
    Array* ptr_array;
    BinarySearchTree* ptr_bst;
    BinaryTrie* ptr_bt; 
    string type;
    vector<int>Inserted_Items;//存储节点中所有的key值
    public:
        DataNode (int id){ 
        //初始化，设置id，分配内存给data 
        Nodeid = id;
        ptr_array = new Array();
        type = "Array";
        }
        void insert(int key,int value){
        //visiting DataNode
        //插入存储节点
        //若数据存在（count inserted_items)，则输出“EXIST"
        //若数据不存在
          //插入inserted_items容器中
          //若type  == Array
             //插入Array.insert
             //若数据个数>=64
                //new ptr_bst, ptr_bst->Update, delete ptr_array, type = bst
          //若type == Bst
             //插入到bst中
             //若6*max_path >= num 
                //nuew ptr_bt, ptr_bt->Update, delete ptr_nst, type = bt
          //若type == Trie 
            //插入到trie中
          //Succesfully Inserted
          cout<<"Visiting data node "<< Nodeid<<" at time "<<timestamp<<endl;
          if(!Inserted_Items.empty()){
            auto iter = find(Inserted_Items.begin(), Inserted_Items.end(), key);
            if(iter != Inserted_Items.end()){
                cout<<"EXIST\n";
                return;
            }
          }
          Inserted_Items.push_back(key);  
          if(type == "Array"){
             ptr_array->insert(key, value);
             if(ptr_array->Array_Size() >= 64){
                 ptr_bst = new BinarySearchTree();
                 ptr_bst->Update_Struct(ptr_array);
                 type = "BinarySearchTree";
                 delete ptr_array;
             }
             cout<<"Succesfully Inserted\n";
             return;
          }
          if(type == "BinarySearchTree"){
             ptr_bst->insert(key, value);
             if(ptr_bst->ChangeStruct()){
                 ptr_bt = new BinaryTrie();
                 ptr_bt->Update_Struct(ptr_bst);
                 type = "BinaryTrie";
                 delete ptr_bst;
             }
             cout<<"Succesfully Inserted\n";
             return;
          }
          if(type == "BinaryTrie"){
             ptr_bt->insert(key, value);
             cout<<"Succesfully Inserted\n";
             return;
          }  
        }
        string getvalue(int key){
        //获取存储节点中key对应的value
          if(type == "Array"){
              return ptr_array->query(key);
          }
          if(type == "BinarySearchTree"){
              return ptr_bst->query(key);
          }
          if(type == "BinaryTrie"){
              return ptr_bt->query(key);
          }
          return "NOT FOUND";

        }
        string query(int key){
        //visiting DataNode
        //查询key(Inserted_Items)，若有，根据type调用相应query函数，返回value并输出，若没有，返回“NOT FOUND"并输出
          cout<<"Visiting data node "<< Nodeid<<" at time "<<timestamp<<endl;
          if(count(Inserted_Items.begin(), Inserted_Items.end(), key) >0 ){
            string result = getvalue(key);
            cout<<result<<"\n";
            return result;
          }
          cout<<"NOT FOUND\n";
          return "NOT FOUND";
          
        }
        void update(int key,int value){
        //visiting DataNode
        //修改存储节点的一个数据，
        //若数据存在(Inserted_items)，输出 旧 新
        //若数据不存在，调用insert(k,v) 
          if(count(Inserted_Items.begin(), Inserted_Items.end(), key) >0 ) {
              string oldvalue = getvalue(key);
              if(type == "Array"){
                  cout<<"Visiting data node "<< Nodeid<<" at time "<<timestamp<<endl;
                  ptr_array->update(key, value);
                  cout<<oldvalue<<" "<<value<<"\n";
                  //cout<<"Visiting data node "<< Nodeid<<" at time "<<timestamp<<endl;
                  return ;
              }
              if(type == "BinarySearchTree"){
                  cout<<"Visiting data node "<< Nodeid<<" at time "<<timestamp<<endl;
                  ptr_bst->update(key, value);
                  cout<<oldvalue<<" "<<value<<"\n";
                  //cout<<"Visiting data node "<< Nodeid<<" at time "<<timestamp<<endl;
                  return ;
              }
              if(type == "BinaryTrie"){
                  cout<<"Visiting data node "<< Nodeid<<" at time "<<timestamp<<endl;
                  ptr_bt->update(key, value);
                  cout<<oldvalue<<" "<<value<<"\n";
                  //cout<<"Visiting data node "<< Nodeid<<" at time "<<timestamp<<endl;
                  return ;
              }
          }
          insert(key, value);
          return ;
        }
        
        //void validate(){
            
        //}

        void GetNode(){
            cout<<"Visiting data node "<< Nodeid<<" at time "<<timestamp<<endl;
            if(type == "Array"){
                ptr_array->GetNode();
                return;
            }
            if(type == "BinarySearchTree"){
                ptr_bst->GetNode();
                return;
            }
            if(type == "BinaryTrie"){
                ptr_bt->GetNode();
                return;
            }
            
        }
};


class ComputingNode{
    //计算节点（m个）
    int Nodeid;
    vector<pair<int,string> > cache; //计算节点缓存（大小为k个pair），最后一个元素为最新的访问的元素
    vector<int> TimeStamp;
    int LocalTime;//for cache replacement 修改缓存
    int CacheSize;//k
    bool isBusy;//若当下时间戳有别的指令（包括修改缓存），此时若用户指令则busy，若需要修改缓存则忽略此条
    public:
        ComputingNode (int id,int k){ 
            CacheSize=k;
            Nodeid=id;
            LocalTime=0;
            isBusy=false;
            
        }
        void free(){isBusy=false;} //每更新一次时间戳，重置free
        bool IsBusy(){return isBusy;} //判断是否busy

        void AddToCache(int key, string value){
        //每次访问计算节点，更新缓存（计算节点）
        //busy
        //若key不存在，则插入到容器最后一个位置，若容器大小超过k，则删除第一个数据
        //若key存在，则找到这个数据，删除，插入新数据到最后一个位置
          isBusy = true;
          vector<pair<int,string>>::iterator cache_iter;
          for(cache_iter = cache.begin(); cache_iter != cache.end(); cache_iter++){
              if(cache_iter->first == key){
                  cache.erase(cache_iter);
                  cache.push_back(make_pair(key, value));
                  return;
              }
          }
          cache.push_back(make_pair(key, value));
          if(cache.size()>CacheSize){
              cache.erase(cache.begin());
          }
          return;  
        }

        void UpdateCache(int key,string value){
        //Update指令后，更新有对应数据的计算节点缓存,但不改变缓存中数据存储的先后顺序
        vector<pair<int,string>>::iterator cache_iter;
        for(cache_iter = cache.begin(); cache_iter != cache.end(); cache_iter++){
            if(cache_iter ->first == key){
                cout<<"Visiting computing node "<<Nodeid<<" at time "<<timestamp<<"\n";
                cache_iter->second = value;
                return;
            }
        }
        return;
        }

        string SearchCache(int key){
        //找缓存中是否有key值，若有，返回value(string)，若没有，返回“NOT FOUND"
        vector<pair<int,string>>::iterator cache_iter;
        for(cache_iter = cache.begin(); cache_iter != cache.end(); cache_iter++){
            if(cache_iter ->first == key){
                return cache_iter->second;
            }
        }
        return "NOT FOUND";
        }

        void ServeInsert(int key,int value,int n,vector<DataNode>&DNode){
            isBusy=true;
            cout<<"Visiting Computing node "<< Nodeid<<" at time "<<timestamp<<endl;
            DNode[key%n].insert(key,value);//插入存储节点
            AddToCache(key, DNode[key%n].getvalue(key));//更新计算节点缓存
        }

        void ServeQuery(int key,int n,vector<DataNode>&DNode){
            isBusy=true;
            cout<<"Visiting Computing node "<< Nodeid<<" at time "<<timestamp<<endl;
            //若缓存中已有这个数据，则直接输出其value
            if(SearchCache(key)!="NOT FOUND"){
                cout<<SearchCache(key)<<endl;
                return;
            }
            //若缓存中没有这个数据，则前往对应存储节点中查找，并更新计算节点缓存
            string temp=DNode[key%n].query(key);
            AddToCache(key, temp);
        }

        void ServeUpdate(int key,int value,int n,vector<DataNode>&DNode){
            isBusy=true;
            cout<<"Visiting Computing node "<< Nodeid<<" at time "<<timestamp<<endl;
            DNode[key%n].update(key,value);//更新存储节点数据
            AddToCache(key, to_string(value));//更新计算节点缓存数据
            
        }
        
        void ServeGetNode(int DataNodeId,vector<DataNode>&DNode){
            isBusy=true;
            cout<<"Visiting Computing node "<< Nodeid<<" at time "<<timestamp<<endl;
            DNode[DataNodeId].GetNode();//前往对应存储节点
        }
};



class DistributedDatabase{
    int CNodeNum;//m
    int DNodeNum;//n
    vector<int>InsNums; //每个计算节点对应执行的操作数
    vector<ComputingNode>CNode;
    vector<DataNode>DNode;
    public:
        int TotalIns; //指令数
        DistributedDatabase(int m,int n,int k){
            CNodeNum=m;
            DNodeNum=n;
            TotalIns=0;
            
            for(int i=0;i<m;++i){
                //创建计算节点
                ComputingNode temp(i,k);
                CNode.push_back(temp); 
                InsNums.push_back(0);
            }
            
            for(int i=0;i<n;++i){
                //创建存储节点
                DataNode temp(i);
                DNode.push_back(temp);
            }
        }
        
        int GetServiceNode(){
        //返回 当前操作次数最少 且 闲置 的计算节点id 
          int min_id = -1;
          int min_num = TotalIns;
          for(int i=0; i<CNodeNum; i++){
            if( CNode[i].IsBusy() == false && InsNums[i] < min_num){
              min_id = i;
              min_num = InsNums[i];
            }
          }
          return min_id;
        }

        void Serve(string instruct){
            //++TotalIns;
            int Nodeid;
            istringstream str(instruct);
            
            string out;
            vector<string>ins;
            while(str>>out){
                ins.push_back(out);
            }
            // 若ins为时间戳：更新tiemstamp, free Cnode
            // 若ins为指令: 调用相应serve函数(先判断节点是否busy), 对应计算节点操作数+1
            if(ins.size() == 1){
                timestamp = stoi(ins[0]);
                for(int i=0; i<CNodeNum; i++){
                   CNode[i].free();
                }
                return;
            }
            ++TotalIns;/////////////////////////////////////////////////////////////
            if(ins[0] == "Insert"){
                if(ins.size() == 4){
                    int cur_id = stoi(ins[3]);
                    if(CNode[cur_id].IsBusy() == false){
                      CNode[cur_id].ServeInsert(stoi(ins[1]), stoi(ins[2]), DNodeNum, DNode); 
                      InsNums[cur_id] +=1;
                    }
                    else{
                        cout<<"REJECT\n";
                    }
                    return;
                }
                if(ins.size() == 3){
                    int cur_id = GetServiceNode();
                    if(cur_id != -1){
                      CNode[cur_id].ServeInsert(stoi(ins[1]), stoi(ins[2]), DNodeNum, DNode);
                      InsNums[cur_id] += 1;
                    }
                    else{
                        cout<<"REJECT\n";
                    }
                    return;
                }
            }
            if(ins[0] == "Query"){
                if(ins.size() == 3){
                    int cur_id = stoi(ins[2]);
                    if(CNode[cur_id].IsBusy() == false){
                      CNode[cur_id].ServeQuery(stoi(ins[1]), DNodeNum, DNode);
                      InsNums[cur_id] += 1;
                    }
                    else{
                        cout<<"REJECT\n";
                    }
                    return;
                }
                if(ins.size() == 2){
                    int cur_id = GetServiceNode();
                    if(cur_id != -1){
                      CNode[cur_id].ServeQuery(stoi(ins[1]), DNodeNum, DNode);
                      InsNums[cur_id] +=1;
                    }
                    else{
                        cout<<"REJECT\n";
                    }
                    return;
                }
            }
            if(ins[0] == "Update"){
                if(ins.size() == 4){
                    int cur_id = stoi(ins[3]);
                    if(CNode[cur_id].IsBusy() == false){
                      CNode[cur_id].ServeUpdate(stoi(ins[1]), stoi(ins[2]), DNodeNum, DNode);
                      InsNums[cur_id] +=1;
                      
                    }
                    else{
                        cout<<"REJECT\n";
                    }
                    //还要同步修改所有其他计算节点的缓存，busy不影响修改
                    for(int i=0; i<CNodeNum && i != cur_id; i++){
                        CNode[i].UpdateCache(stoi(ins[1]), ins[2]);
                    }
                    return;
                }
                if(ins.size() == 3){
                    int cur_id = GetServiceNode();
                    if(cur_id != -1){
                      CNode[cur_id].ServeUpdate(stoi(ins[1]), stoi(ins[2]), DNodeNum, DNode);
                      InsNums[cur_id] +=1;
                    }
                    else{
                        cout<<"REJECT\n";
                    }
                    //还要同步修改所有其他计算节点的缓存，busy不影响修改
                    for(int i=0; i<CNodeNum && i != cur_id; i++){
                        CNode[i].UpdateCache(stoi(ins[1]), ins[2]);
                    }
                    return;
                }
            }
            if(ins[0] == "GetNode"){
                if(ins.size() == 3){
                    int cur_id = stoi(ins[2]);
                    if(CNode[cur_id].IsBusy() == false){
                      CNode[cur_id].ServeGetNode(stoi(ins[1]), DNode);
                      InsNums[cur_id] +=1;
                    }
                    else{
                        cout<<"REJECT\n";
                    }
                    return;
                }
                if(ins.size() == 2){
                    int cur_id = GetServiceNode();
                    if(cur_id != -1){
                      CNode[cur_id].ServeGetNode(stoi(ins[1]), DNode);
                      InsNums[cur_id] +=1;
                    }
                    else{
                        cout<<"REJECT\n";
                    }
                    return;
                }
            }
            
        }
};


int main(){
    int m,n,k,N;
    ifstream inputfile;
    inputfile.open("input1");
    string frst;
    getline(inputfile, frst);
    istringstream param(frst);
    param>>m>>n>>k>>N;
    DistributedDatabase a(m,n,k);
    while(a.TotalIns<N ){
        string instruct;
        getline(inputfile,instruct);
        a.Serve(instruct);
    }
    inputfile.close();
    cout<<"complete\n";/////////////////////////////////////////////////////////////////
}
