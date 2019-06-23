# BugReports
This is a static library, which supports system of bug reports. 
- Function saveLog() saves new log to a log file. To control log files the ring buffer is used.
- Function initWithDefault() initializes a log system, which has five files to keep logs. Each file can have maximum 16KB.

Used:
- C
