Из папки build выполнить следующие команды

для генерации файлов сборки: cmake ..
для сборки: cmake --build .
для запуска приложения: ./bin/pc_porthole
для сборки и запуска: cmake --build . && ./bin/pc_porthole 


для запуска приложения на дискретной видеокарте в линуксе: cmake --build . && DRI_PRIME=1 ./bin/pc_porthole 
для проверки 3d в линукс: gears
для проверки 3d в линукс на дискретной карте: DRI_PRIME=1 gears

