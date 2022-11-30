namespace BridgePattern
{
	internal class TV : BaseDevice
	{
		const uint CHN_MIN = 1;
		const uint CHN_MAX = 50;
		const uint CHN_STEP = 1;

		public TV()
		{
			_name = "TV";
			_channelNow = 1;
		}

		public override void SetChannel(uint channel)
		{
			if (channel < CHN_MIN)
			{
				channel = CHN_MIN;
			}
			else if (channel > CHN_MAX)
			{
				channel = CHN_MAX;
			}

			_channelNow = channel;
			Log("Channel set to " + _channelNow);
		}

		public override Dictionary<string, uint> GetLimits()
		{
			Dictionary<string, uint> limits = new Dictionary<string, uint>();
			limits.Add("CHN_MIN", CHN_MIN);
			limits.Add("CHN_MAX", CHN_MAX);
			limits.Add("CHN_STEP", CHN_STEP);

			return limits;
		}

		public override string ToString()
		{
			return ("Device Type: TV"
					+ "\nName: " + _name
					+ "\nPower: " + (_powerState ? "On" : "Off")
					+ "\nVolume: " + _volume
					+ "\nChannel: " + _channelNow
					+ "\nChannel Min: " + CHN_MIN
					+ "\nChannel Max: " + CHN_MAX);
		}
	}
}
