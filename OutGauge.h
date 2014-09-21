#ifndef OUTGAUGE_H
#define OUTGAUGE_H


struct OutGaugePacket
{
   qint32 Time;
   char Car[4];
   quint16 Flags;
   quint8 Gear;
   quint8 PLID;
   float Speed;
   float RPM;
   float Turbo;
   float EngTemp;
   float Fuel;
   float OilPressure;
   float OilTemp;
   quint32 DashLights;
   quint32 ShowLights;
   float Throttle;
   float Brake;
   float Clutch;
   quint8 rawDisplay1[16];
   quint8 rawDisplay2[16];
};

#endif // OUTGAUGE_H
