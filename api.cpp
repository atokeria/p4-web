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
   :queue(queue){
  }

  void Application_Post(int position){
    json in;
    cin >> in;
    Student student;
    student.name = in["uniqname"];
    student.location = in["location"];
    queue.push_back(student);
    json j2 = {
      {"location", "student.location"},
      {"position", position},
      {"uniqname", "student.name"},
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
    cout << endl;
  }



};

int main() {
  string method,path,dumpy;
  while(cin >> method >> path){
    cin >> dumpy >> dumpy >> dumpy >> dumpy >> dumpy >> dumpy >> dumpy >> dumpy;
  }
}
