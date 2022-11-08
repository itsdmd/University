namespace BridgePattern
{
	internal class TVController : BaseController
	{
		public TVController(IDevice device) : base(device) { }

		// Platform-specic methods
		public void Mute()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change volume. Device is disabled.");
				return;
			}

			_device.SetVolume(0);
		}
	}
}