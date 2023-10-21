dependency:
	cd build && cmake .. && make

prepare:
	rm -rf build
	mkdir build

exec:
	cd build/app/time_value && ./executable_time_value
