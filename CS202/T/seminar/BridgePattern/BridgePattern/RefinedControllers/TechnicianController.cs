namespace BridgePattern
{
	internal class TechnicianController : BaseController
	{
		public TechnicianController(IDevice device) : base(device) { }

		// Platform-specic methods
		public void Reassign(IDevice newDevice)
		{
			_device = newDevice;
			_device.Log("New controller had been assigned");
		}

		public void SetName(string name)
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change property. Device is disabled.");
				return;
			}

			_device.SetName(name);
		}

		public void SetChannel(uint channel)
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change channel. Device is disabled.");
				return;
			}

			_device.SetChannel(channel);
		}

		public void GetLimits()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot display values. Device is disabled.");
				return;
			}

			Dictionary<string, uint> limits = _device.GetLimits();
			foreach (KeyValuePair<string, uint> kvp in limits)
			{
				Console.WriteLine(kvp.Key + " = " + kvp.Value);
			}
		}

		public void RestartDevice()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Device is already disabled.");
				return;
			}

			_device.Disable();
			_device.Enable();
		}
	}
}