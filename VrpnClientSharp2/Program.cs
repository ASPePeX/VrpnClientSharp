using System;
using VrpnClientLib;


namespace VrpnClientSharp2
{
    class Program
    {
        static void Main(string[] args)
        {
            VrpnClientController client = new VrpnClientController();
            int idx1 = client.AddAnalog("Mouse1@localhost");
            int idx2 = client.AddAnalog("Mouse0@localhost");
            int idx3 = client.AddAnalog("Mouse2@localhost");

            double[] blub1 = new double[2];
            double[] blub2 = new double[2];
            double[] blub3 = new double[2];

            while (true)
            {
                blub1 = client.GetAnalogData(idx1);
                blub2 = client.GetAnalogData(idx2);
                blub3 = client.GetAnalogData(idx3);
                Console.Clear();

                Console.WriteLine("Mouse Axis 1     : " + blub1[0] + " " + blub1[1]);
                Console.WriteLine("Mouse Axis 2     : " + blub2[0] + " " + blub2[1]);
                Console.WriteLine("Mouse Axis 3     : " + blub3[0] + " " + blub3[1]);
                //Console.WriteLine("Keyboard Buttons: " + blub2[0] + " " + blub2[1]);
                //Console.WriteLine("Tracker Axis    : " + blub1[0] + " " + blub1[1] + " " + blub1[2] + " " + blub1[3] + " " + blub1[4] + " " + blub1[5] + " " + blub1[6]);

                //System.Threading.Thread.Sleep(5000);
            }
        }
    }
}
