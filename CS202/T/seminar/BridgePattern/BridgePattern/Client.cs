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
			TVController _tvCtrl_tv = new TVController(_tv);
			TVController _tvCtrl_rd = new TVController(_radio);

			RadioController _radioCtrl_tv = new RadioController(_tv);
			RadioController _radioCtrl_rd = new RadioController(_radio);

			TechnicianController _techCtr_tv = new TechnicianController(_tv);
			TechnicianController _techCtr_rd = new TechnicianController(_radio);

			/* ---------------------------------- Tests --------------------------------- */
			Console.WriteLine("===== TV Controller =====");
			_tvCtrl_tv.VolumeUp();
			_tvCtrl_rd.VolumeUp();
			Console.WriteLine("\n");

			_tvCtrl_tv.TogglePower();
			_tvCtrl_rd.TogglePower();
			Console.WriteLine("\n");
			
			_tvCtrl_tv.Mute();
			_tvCtrl_rd.Mute();
			Console.WriteLine("\n");

			_tvCtrl_tv.ChannelUp();
			_tvCtrl_tv.ChannelDown();
			_tvCtrl_tv.ChannelDown();
			Console.WriteLine("\n");

			_tvCtrl_rd.ChannelDown();
			_tvCtrl_rd.ChannelDown();
			Console.WriteLine("\n");

			Console.WriteLine("===== Radio Controller =====");
			_radioCtrl_tv.ChannelUp();
			_radioCtrl_rd.ChannelUp();
			Console.WriteLine("\n");

			_radioCtrl_tv.ToggleFM();
			_radioCtrl_rd.ToggleFM();
			Console.WriteLine("\n");

			Console.WriteLine("===== Technician's Controller =====");
			_techCtr_tv.SetName("Television");
			_techCtr_rd.SetName("Radio X");
			Console.WriteLine("\n");

			_techCtr_tv.SetChannel(25);
			_techCtr_rd.SetChannel(1234);
			Console.WriteLine("\n");

			_techCtr_tv.Reassign(_radio);
			_techCtr_rd.Reassign(_tv);
			Console.WriteLine("\n");

			_techCtr_tv.GetLimits();
			Console.WriteLine("\n");
			_techCtr_rd.GetLimits();
			Console.WriteLine("\n");

			_techCtr_tv.TogglePower();
			_techCtr_rd.TogglePower();
		}
	}
}