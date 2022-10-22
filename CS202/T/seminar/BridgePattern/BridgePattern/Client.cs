using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BridgePattern
{
	class Client
	{
		internal static void Main(string[] args)
		{
            /* --------------------------------- Devices -------------------------------- */
			IDevice _tv = new TV();
			IDevice _radio = new Radio();

			/* ------------------------------- Controllers ------------------------------ */
			BasicController _basicCtrl_1 = new BasicController(_tv);
			BasicController _basicCtrl_2 = new BasicController(_radio);

			TVController _tvCtrl_1 = new TVController(_tv);
			TVController _tvCtrl_2 = new TVController(_radio);

			RadioController _radioCtrl_1 = new RadioController(_tv);
			RadioController _radioCtrl_2 = new RadioController(_radio);

			TechnicianController _techCtr_1 = new TechnicianController(_tv);
			TechnicianController _techCtr_2 = new TechnicianController(_radio);

			/* ---------------------------------- Tests --------------------------------- */
			Console.WriteLine("===== Basic Controller =====");
			_basicCtrl_1.VolumeUp();
			_basicCtrl_2.VolumeUp();
			Console.WriteLine("\n");

			_basicCtrl_1.TogglePower();
            _basicCtrl_2.TogglePower();
			Console.WriteLine("\n");

            _basicCtrl_1.VolumeUp();
            _basicCtrl_2.VolumeUp();
			Console.WriteLine("\n");

			_basicCtrl_1.ChannelUp();
			_basicCtrl_1.ChannelDown();
			_basicCtrl_1.ChannelDown();
			_basicCtrl_2.ChannelUp();
			Console.WriteLine("\n");

			Console.WriteLine("===== TV Controller =====");
			_tvCtrl_1.Mute();
			_tvCtrl_2.Mute();
			Console.WriteLine("\n");

			_tvCtrl_1.ChannelDown();
			_tvCtrl_1.ChannelDown();
			_tvCtrl_1.ChannelDown();
			Console.WriteLine("\n");

			_tvCtrl_2.ChannelDown();
			Console.WriteLine("\n");

			Console.WriteLine("===== Radio Controller =====");
			_radioCtrl_1.ChannelUp();
			_radioCtrl_2.ChannelUp();
			Console.WriteLine("\n");

			_radioCtrl_1.ToggleFM();
			_radioCtrl_2.ToggleFM();
			Console.WriteLine("\n");

			Console.WriteLine("===== Technician's Controller =====");
			_techCtr_1.SetName("Television");
			_techCtr_2.SetName("Radio X");
			Console.WriteLine("\n");

			_techCtr_1.SetChannel(25);
			_techCtr_2.SetChannel(1234);
			Console.WriteLine("\n");

			_techCtr_1.GetLimits();
			Console.WriteLine("\n");
			_techCtr_2.GetLimits();
		}
	}
}