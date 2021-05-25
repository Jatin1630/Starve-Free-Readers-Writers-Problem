  struct ProcessBlock{
      ProcessBlock* next;
      int* process_block;
  }

  struct Queue{
      ProcessBlock* front, rear;
      void* push(int* value){
          ProcessBlock* block = new ProcessBlock();
          blk->value = value;
          if(rear != nullptr){
              rear->next = block;
              rear = block;
          }
          else{
            front = rear = n;
          }
      }
      int* pop(){
          if(front == nullptr)
              return -1;          
          else{
              int* val = front->value;
              front = front->next;
              if(front == nullptr)
              {
                  rear = nullptr;
              }
              return val;
          }
      }


  }

      struct Semaphore{
        int value = 1;
        Queue* Qu = new Queue();
      }

      void wait(Semaphore Sema,int PID){
        Sema->value--;
        if(Sema->value < 0){
        Sema->Qu->push(PID);
        block();
        }
      }

      void signal(Semaphore *Sema){
        Sema->value++;
        if(Sema->value <= 0){
        int* PID = Sema->Qu->pop();
        wakeup(PID);
        }
      }





