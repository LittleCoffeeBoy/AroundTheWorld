// CV: CreateVehicles
public CV_OnGameModeInit()
{
	/*
	-* Adicionando caminh�es/cargas no primeiro spawn em Las Venturas.
	*/
	CreateVehicle(515, 2884.5701, 937.3307, 11.7565, 90.8847, 0, 0, 100);
	CreateVehicle(515, 2884.5500, 932.2507, 11.7565, 90.8847, 0, 0, 100);
	CreateVehicle(515, 2884.5701, 927.0707, 11.7565, 90.8847, 0, 0, 100);
	CreateVehicle(515, 2884.5701, 921.8907, 11.7565, 90.8847, 0, 0, 100);
	CreateVehicle(455, 2884.9529, 916.7742, 11.0996, 90.8847, 0, 0, 100);
	CreateVehicle(455, 2884.9500, 911.5732, 11.0996, 90.8847, 0, 0, 100);
	CreateVehicle(455, 2884.9500, 906.7932, 11.0996, 90.8847, 0, 0, 100);
	CreateVehicle(455, 2884.9500, 902.1332, 11.0996, 90.8847, 0, 0, 100);
	CreateVehicle(435, 2850.4954, 894.9935, 11.1899, 0.0000, 0, 0, 100);
	CreateVehicle(435, 2846.3752, 894.9935, 11.1899, 0.0000, 0, 0, 100);
	CreateVehicle(435, 2842.3953, 894.9935, 11.1899, 0.0000, 0, 0, 100);
	CreateVehicle(435, 2838.1155, 894.9735, 11.1899, 0.0000, 0, 0, 100);
	CreateVehicle(578, 2786.6951, 957.2338, 11.2447, 270.9657, 0, 0, 100);
	CreateVehicle(578, 2786.6951, 962.1538, 11.2447, 270.9657, 0, 0, 100);
	CreateVehicle(578, 2786.6951, 952.4538, 11.2447, 270.9657, 0, 0, 100);
	CreateVehicle(578, 2786.6951, 947.8338, 11.2447, 270.9657, 0, 0, 100);
	// ------------------------------------------------------------------
	
	return 1;
}

// Bug quando cai da moto n�o fecha o painel do vehiculo.
stock GetVehicleSpeed(vehicleid)
{
	new Float:vehiclePosX, Float:vehiclePosY, Float:vehiclePosZ;

	GetVehicleVelocity(vehicleid, vehiclePosX, vehiclePosY, vehiclePosZ);

	//printf("%i", floatround(floatsqroot((vehiclePosX * vehiclePosX) + (vehiclePosY * vehiclePosY) + (vehiclePosZ * vehiclePosZ)) * 181.5));

	return floatround(floatsqroot((vehiclePosX * vehiclePosX) + (vehiclePosY * vehiclePosY) + (vehiclePosZ * vehiclePosZ)) * 181.5);
}