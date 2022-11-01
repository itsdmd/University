namespace BridgePattern
{
	internal interface IDevice
	{
		void SetName(string name);
		string GetName();
		bool IsEnabled();
		void Enable();
		void Disable();
		uint GetVolume();
		void SetVolume(uint percent);
		uint GetChannel();
		void SetChannel(uint channel);
		string GetMode();
		void SetMode(string mode);
		Dictionary<string, uint> GetLimits();
		void Log(string message);
	}
}