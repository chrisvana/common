// Copyright 2013
// Author: Christopher Van Arsdale

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string>

using std::string;

namespace util {
namespace {
class Pipe {
 public:
  Pipe() : in_open_(false), out_open_(false) {
    if (pipe(fd_) >= 0) {
      in_open_ = out_open_ = true;
    }
  }

  ~Pipe() {
    CloseIn();
    CloseOut();
  }

  // Status
  bool IsOpen() const { return in_open_ || out_open_; }

  // Accessors
  int In() const { return fd_[0]; }
  int Out() const { return fd_[1]; }

  // Close.
  void Close() {
    CloseIn();
    CloseOut();
  }
  void CloseIn() {
    if (in_open_) {
      close(In());
      in_open_ = false;
    }
  }
  void CloseOut() {
    if (out_open_) {
      close(Out());
      out_open_ = false;
    }
  }

 private:
  bool in_open_, out_open_;
  int fd_[2];
};
}  // anonymous namespace

int Execute(const string& stdin,
            const string& command,
            string* stdout) {
  Pipe in, out;
  if (!in.IsOpen() || !out.IsOpen()) {
    return -1;
  }

  // Start fork
  int pid = fork();
  if (pid == -1) {
    return -1;
  }

  // If child
  if (pid == 0) {
    // Redirect pipe to stdin.
    if (dup2(in.In(), 0) == -1) {
      return -1;
    }

    // Redirect pipe to stdout.
    if (dup2(out.Out(), 1) == -1) {
      return -1;
    }

    // Not needed anymore.
    in.Close();
    out.Close();
    int status = system(command.c_str());
    if (WIFEXITED(status)) {
      _exit(WEXITSTATUS(status));
    } else {
      _exit(EXIT_FAILURE);
    }
    return -1;
  } else {
    in.CloseIn();
    out.CloseOut();
    if (write(in.Out(), stdin.data(), stdin.size()) == -1) {
      // what to do?
    }
    const int kBufferSize = 256;
    char buffer[kBufferSize];
    size_t size ;
    while ((size = read(out.In(), buffer, kBufferSize))) {
      if (stdout) {
        stdout->append(buffer, size);
      }
    }
    int child_status;
    waitpid(pid, &child_status, 0);
    if (WIFEXITED(child_status)) {
      return WEXITSTATUS(child_status);
    }
    return -1;
  }
}

int Execute(const string& command, string* stdout) {
  return Execute("", command, stdout);
}

int Execute(const string& command) {
  return Execute("", command, NULL);
}

}  // namespace util
