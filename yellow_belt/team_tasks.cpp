#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <sstream>

using namespace std;

//enum class TaskStatus {
//    NEW,          // новая
//    IN_PROGRESS,  // в разработке
//    TESTING,      // на тестировании
//    DONE          // завершена
//};
enum class ComandNames {
    AddNewTask,
    GetPersonTasksInfo,
    PerformPersonTasks

};
//using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
      return team_tasks.at(person);
    };

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person){
      team_tasks[person][TaskStatus::NEW] += 1;
    };

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count){
      TasksInfo new_tasks;
      TasksInfo old_tasks;

      int left_tasks = 0;
      int come_tasks = 0;
      int i =0;
      while (i < 4){
        int tmp = 0;
        if(come_tasks!=0){
          new_tasks[static_cast<TaskStatus>(i)]= come_tasks;
          tmp += come_tasks;
        }
        left_tasks = min(task_count, team_tasks[person][static_cast<TaskStatus>(i)]);
        if (i != 3){
          if (team_tasks[person][static_cast<TaskStatus>(i)] - left_tasks != 0 ){
            old_tasks[static_cast<TaskStatus>(i)] = team_tasks[person][static_cast<TaskStatus>(i)] - left_tasks;
            tmp += team_tasks[person][static_cast<TaskStatus>(i)] - left_tasks;

          }
        } else {
          tmp += team_tasks[person][static_cast<TaskStatus>(i)];
        }
        team_tasks[person][static_cast<TaskStatus>(i)] = tmp;
        task_count = task_count - left_tasks;
        come_tasks = left_tasks;
        i++;
      }
      return tie(new_tasks, old_tasks);

    };

private:
    map<string, TasksInfo> team_tasks;
};
// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << "{ " ;
    if (tasks_info[TaskStatus::NEW] != 0){
      cout << "NEW: " << tasks_info[TaskStatus::NEW] <<", ";
    }
    if (tasks_info[TaskStatus::IN_PROGRESS] != 0){
      cout << "IN_PROGRESS: " << tasks_info[TaskStatus::IN_PROGRESS] <<", ";
    }
  if (tasks_info[TaskStatus::TESTING] != 0){
    cout << "TESTING: " << tasks_info[TaskStatus::TESTING] <<", ";
  }
  if (tasks_info[TaskStatus::DONE] != 0){
    cout << "DONE: " << tasks_info[TaskStatus::DONE] <<" ";
  }
  cout << " }";
}


int main() {
  TeamTasks tasks;
  string s;
  while(getline(cin, s)){
    stringstream ss;
    ss << s;
    string comand;
    getline(ss, comand, ' ');
    if (comand == "AddNewTasks"){
      string person;
      getline(ss, person, ' ');
      int task_nums;
      ss >> task_nums;
      for (int i = 0; i < task_nums; i++){
        tasks.AddNewTask(person);
      }
    }
    if (comand == "PerformPersonTasks"){
      string person;
      getline(ss, person, ' ');
      int task_count;
      ss >> task_count;
      TasksInfo new_tasks, old_tasks;
      tie(new_tasks, old_tasks) = tasks.PerformPersonTasks(person, task_count);
      cout << '[';
      PrintTasksInfo(new_tasks);
      cout << " ";
      PrintTasksInfo(old_tasks);
      cout << ']' << endl;
    }
    if (comand == "GetPersonTasksInfo"){
      string person;
      getline(ss, person, ' ');
      TasksInfo task_info = tasks.GetPersonTasksInfo(person);
      PrintTasksInfo(task_info);
      cout << endl;
    }
  }
  return 0;
}
