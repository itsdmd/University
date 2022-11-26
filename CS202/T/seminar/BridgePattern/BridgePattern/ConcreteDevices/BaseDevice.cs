namespace BridgePattern
{
	internal abstract class BaseDevice : IDevice
	{
		protected string _name = "";
		protected bool _powerState = false;
		protected uint _volume = 0;
		protected uint _channelNow = 0;
		
		public BaseDevice() { }

		public virtual void SetName(string name)
		{
			string _oldName = _name;
			_name = name;
			Log("Renamed from \"" + _oldName + "\"");
		}

		public virtual string GetName()
		{
			return _name;
		}

		public virtual void Disable()
		{
			_powerState = false;
			Log("Turned off");
		}

		public virtual void Enable()
		{
			_powerState = true;
			Log("Turned on");
		}

		public virtual bool IsEnabled()
		{
			return _powerState;
		}

		public virtual uint GetChannel()
		{
			return (uint)_channelNow;
		}

		public abstract void SetChannel(uint channel);

		public virtual uint GetVolume()
		{
			return (uint)_volume;
		}

		public virtual void SetVolume(uint percent)
		{
			if (percent < 0)
			{
				percent = 0;
			}
			else if (percent > 100)
			{
				percent = 100;
			}

			_volume = percent;
			Log("Volume set to " + _volume + "%");
		}

		public abstract Dictionary<string, uint> GetLimits();

		public virtual void Log(string message)
		{
			Console.WriteLine($"{_name}: {message}");
		}

		public virtual string GetMode()
		{
			Log(_name + " has no mode.");
			return "";
		}

		public virtual void SetMode(string mode)
		{
			Log(_name + " can't be set mode.");
		}
	}
}
