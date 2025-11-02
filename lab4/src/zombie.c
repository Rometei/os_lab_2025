#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Родительский процесс PID: %d\n", getpid());

    pid_t pid = fork();
    
    if (pid == 0) {
        printf("Дочерний процесс PID: %d\n", getpid());
        printf("Дочерний процесс завершается через 5 секунд...\n");
        sleep(5);
        printf("Дочерний процесс завершен, но станет зомби!\n");
        exit(0);  // Дочерний процесс завершается
    } else if (pid > 0) {
        // Родительский процесс
        printf("Родительский процесс создал дочерний с PID: %d\n", pid);       
        // Родитель НЕ вызывает wait() - это создает зомби!
        sleep(15);  // Ждем 15
        
        wait(NULL);  // Теперь убираем зомби
        printf("Зомби-процесс убран!\n");
        
        sleep(5);  // Даем время убедиться, что зомби исчез
    } else {
        perror("Ошибка при вызове fork()");
        return 1;
    }
    
    return 0;
}