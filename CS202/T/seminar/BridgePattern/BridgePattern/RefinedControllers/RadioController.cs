namespace BridgePattern
{
	internal class RadioController : BaseController
	{
		public RadioController(IDevice device) : base(device) { }

		// Platform-specic methods
		public void ToggleFM()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change mode. Device is disabled.");
				return;
			}

			switch (_device.GetMode())
			{
				case "FM":
					_device.SetMode("AM");
					break;
				case "AM":
					_device.SetMode("FM");
					break;
				default:
					_device.Log("Device does not have FM functionality. Unable to change mode.");
					return;
			}
		}
	}
}