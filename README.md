# EnterpriseProject

A Project for enterprise software development module A leave booking system built around Domain Driven patterns and resiliant design

The concept for the project surrounds modular monolith with divided responsibility between the leave booking and staff management

## Building

## Accessessing the database
note for me not really for other users
```bash
psql -d LeaveBooking -h localhost -U pguser
```
### Linux
```bash
make
```

### Windows (cross-compile)
```bash
make windows
```

### Both platforms
```bash
make both
```

### Debug build
```bash
make debug
```

### Configuration
```bash
make config
```

### Testing
```bash
make test
```

## Author

tayloracapula

## License

MIT
