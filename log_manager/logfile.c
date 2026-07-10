#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define LOG_FILE "audit.log"
#define BUFFER_SIZE 1024

// Helper function to write a string using low-level write system call
void print_str(int fd, const char *str) {
    write(fd, str, strlen(str));
}

// Helper function to format and write a number to a file descriptor
void print_num(int fd, int num) {
    char buf[12];
    int i = 10;
    buf[11] = '\0';
    if (num == 0) {
        buf[--i] = '0';
    } else {
        while (num > 0 && i > 0) {
            buf[--i] = (num % 10) + '0';
            num /= 10;
        }
    }
    print_str(fd, &buf[i]);
}

int handle_add(const char *msg) {
    // Open for writing, create if missing, append-only mode, permissions 0644
    int fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) return 1;

    print_str(fd, msg);
    print_str(fd, "\n");
    close(fd);
    return 0;
}

int handle_view(void) {
    int fd = open(LOG_FILE, O_RDONLY);
    if (fd < 0) return 1; // File might not exist yet if no logs are added

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    int line_number = 1;
    int is_start_of_line = 1;

    // Read file chunk by chunk using read system call
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        for (ssize_t i = 0; i < bytes_read; i++) {
            if (is_start_of_line) {
                print_num(1, line_number);
                print_str(1, ": ");
                is_start_of_line = 0;
            }

            // Write character to stdout (file descriptor 1)
            write(1, &buffer[i], 1);

            if (buffer[i] == '\n') {
                line_number++;
                is_start_of_line = 1;
            }
        }
    }

    close(fd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_str(2, "Usage: auditlog [--add \"message\" | --view]\n");
        return 1;
    }

    if (strcmp(argv[1], "--add") == 0 && argc == 3) {
        return handle_add(argv[2]);
    } else if (strcmp(argv[1], "--view") == 0) {
        return handle_view();
    }

    print_str(2, "Invalid arguments.\n");
    return 1;
}
