// Project UID c1f28c309e55405daf00c565d57ff9ad

#include <iostream>
#include <list>
#include "json.hpp"
using nlohmann::json;
#include <string>

using namespace std;

class ohQueue {
  private:
    struct Student
    {
      string name;
      string location;
    };

    list<Student> queue;

  public:

  ohQueue()
   :queue(){
  }

  void error_400(){
    cout << "HTTP/1.1 400 Bad Request" << endl;
    cout << "Content-Type: application/json; charset=utf-8" << endl;
    cout << "Content-Length: " << 0 << endl;
    cout << endl;
  }

  void Application_Post(){
    json in;
    cin >> in;
    Student student;
    student.name = in["uniqname"];
    student.location = in["location"];
    queue.push_back(student);
    json j2 = {
      {"location", student.location},
      {"position", queue.size()},
      {"uniqname", student.name},
    };
    string str2 = j2.dump(4) + "\n";
    size_t content_length = str2.length();
    cout << "HTTP/1.1 " << 201 << " Created" << endl;
    cout << "Content-Type: application/json; charset=utf-8" << endl;
    cout << "Content-Length: " << content_length << endl;
    cout << endl;
    cout << str2;
  }

  void Get_Apply_0(){
    cout << "HTTP/1.1 " << 200 << " OK" << endl;
    cout << "Content-Type: application/json; charset=utf-8" << endl;
    cout << "Content-Length: " << 160 << endl;
    cout << endl;
    json j2 = {
      {"queue_head_url", "http://localhost/queue/head/"},
      {"queue_list_url", "http://localhost/queue/"},
      {"queue_tail_url", "http://localhost/queue/tail/"}
    };
    string str2 = j2.dump(4) + "\n";
    cout << str2;
  }

  void Get_Apply_1(){
    if(queue.size() == 0){
      cout << "HTTP/1.1 400 Bad Request" << endl;
      cout << "Content-Type: application/json; charset=utf-8" << endl;
      cout << "Content-Length: " << 40 << endl;
      cout << endl;
      json j8 = {
        {"count", 0},
        {"results", nullptr}
      };
      string str2 = j8.dump(4) + "\n";
      cout << str2 << endl;
    }else{
      json j1;
      json j2;
      json for_real;
      int j = 1;
      for(std::list<Student>::iterator i = queue.begin(); i != queue.end(); i++){
       j2 = {
          {"location", i->location},
          {"position", j},
          {"uniqname", i->name}
        };
        j1.push_back(j2);
        ++j;
      }
      for_real = {
        {"count", queue.size()},
        {"results", j1}
      };
      string str2 = for_real.dump(4) + "\n";
      size_t content_length = str2.length();
      cout << "HTTP/1.1 200 OK" << endl;
      cout << "Content-Type: application/json; charset=utf-8" << endl;
      cout << "Content-Length: " << content_length << endl;
      cout << endl;
      cout << str2;
    }
  }

  void Get_apply_2(){
    if(queue.size() == 0){
      error_400();
    }else{
      std::list<Student>::iterator i = queue.begin();
      json j2 = {
        {"location", i->location},
        {"position", 1},
        {"uniqname", i->name}
      };
      string str2 = j2.dump(4) + "\n";
      size_t content_length = str2.length();
      cout << "HTTP/1.1 200 OK" << endl;
      cout << "Content-Type: application/json; charset=utf-8" << endl;
      cout << "Content-Length: " << content_length << endl;
      cout << endl;
      cout << str2;
    }
  }

  void Delete_application(){
    if(queue.size() == 0){
      error_400();
    }else{
      queue.pop_front();
      cout << "HTTP/1.1 204 No Content" << endl;
      cout << "Content-Type: application/json; charset=utf-8" << endl;
      cout << "Content-Length: " << 0 << endl;
      cout << endl;
    }
  }


};

int main() {
  ohQueue queue;
  string method,path,dumpy;
  while(cin >> method >> path){
    cin >> dumpy >> dumpy >> dumpy >> dumpy >> dumpy >> dumpy >> dumpy >> dumpy;
    if(method == "GET"){
      if(path == "/api/"){
        queue.Get_Apply_0();
      }
      else if(path == "/api/queue/"){
        queue.Get_Apply_1();
      }
      else if(path == "/api/queue/head/"){
        queue.Get_apply_2();
      }else{
        cout << "HTTP/1.1 400 Bad Request" << endl;
        cout << "Content-Type: application/json; charset=utf-8" << endl;
        cout << "Content-Length: " << 0 << endl;
        cout << endl;
      }
    }
    else if(method == "POST"){
      if(path == "/api/queue/tail/"){
        queue.Application_Post();
      }else{
        cout << "HTTP/1.1 400 Bad Request" << endl;
        cout << "Content-Type: application/json; charset=utf-8" << endl;
        cout << "Content-Length: " << 0 << endl;
        cout << endl;
      }
    }
    else if(method == "DELETE"){
      if(path == "/api/queue/head/"){
        queue.Delete_application();
      }else{
        cout << "HTTP/1.1 400 Bad Request" << endl;
        cout << "Content-Type: application/json; charset=utf-8" << endl;
        cout << "Content-Length: " << 0 << endl;
        cout << endl;
      }
    }
  }
}
