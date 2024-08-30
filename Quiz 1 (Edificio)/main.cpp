#include "Building.h"

int main(){

    Building office;
    
    bool buildInter = true;
    bool floorInter = true;
    int option = 0, floorOption, floor, deleteFloor;

    while (buildInter) {
        cout << "[Interfaz de edificio activa] que desea hacer?\n";
        cout << " 1. Ver pisos\n 2. Ver interfaz de un piso\n 3. Agregar piso\n 4. Eliminar piso\n 5. Verificar valores de ventas\n 6. Cerrar interfaz\n";
        cout << "Opcion: "; cin >> option;
        system("cls");

        switch (option) {
        case 1:
            cout << "[Pisos del edificio]\n\n";
            office.printFloorsWithEmployees();
            system("pause");
            system("cls");
            break;
        case 2:
            floor = 0;
            while (floor <= 0 && !office.floorExist(floor)) {
                cout << "[Eliga el piso al que desea ingresar]\nPiso: "; cin >> floor;

                if (!office.floorExist(floor)) {
                    cout << "\n\nPiso no disponible";
                }
                system("cls");
            }

            floorInter = true;
            floorOption = 0;
            while (floorInter) {

                cout << "[Interfaz de piso# "<< floor << " activa] Que desea hacer?\n";
                cout << " 1. Ver empleados\n 2. Agregar empleado\n 3. Agregar ventas a un empleado\n 4. cerrar interfaz\n";
                cout << "Opcion: "; cin >> floorOption;
                system("cls");

                string name;
                int sales, employee;
                switch (floorOption) {
                case 1:
                    cout << "[Empleados del piso# " << floor <<"]" << endl;
                    office.printEmployeesOfFloor(floor);
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    cout << "[Ingrese el nombre del empleado]\nNombre: ";
                    cin.ignore();
                    getline(cin, name);
                    office.addPersonToFloor(floor, name);
                    system("cls");
                    break;
                case 3:
                    employee = 0;
                    sales = 0;
                    cout << "[Empleados disponibles en el piso# " << floor << "] eliga el numero del empleado\n";
                    office.printEmployeesOfFloor(floor);
                    cout << "A que empleado desea agregarle ventas?\nOpcion: "; cin >> employee;
                    cout << "\nCuantas ventas desea agregar al empleado?\nVentas: "; cin >> sales;
                    office.addSaleToPersonToFloor(floor, employee, sales);
                    system("pause");
                    system("cls");
                    break;
                default:
                    floorInter = false;
                    break;
                }
                floorOption = 0;
            }
            break;
        case 3:
            office.addFloor();
            cout << "[Piso agregado al edificio]\nVista de los pisos actuales: \n\n";
            office.printFloors();
            cout << "\n";
            system("pause");
            system("cls");
            break;
        case 4:
            deleteFloor = 0;
            cout << "[Pisos actuales]\n";
            office.printFloorsWithEmployees();
            cout << "\nPiso a eliminar: "; cin >> deleteFloor;
            office.deleteFloor(deleteFloor);
            cout << "Piso eliminado\n";
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "[Verificacion de pisos en proceso]\n\n";
            office.verifyFloorsSales();
            system("pause");
            system("cls");
            break;
        default:
            cout << "[Cerrando interfaz de edificio]\n";
            system("pause");
            system("cls");
            buildInter = false;
            break;
        }
    }
    office.BuildingManualDestructor();
    return 0;
}