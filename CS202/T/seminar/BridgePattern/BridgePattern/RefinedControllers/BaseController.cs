using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BridgePattern
{
	internal class BaseController : AbstractController
	{
		public BaseController(IDevice device) : base(device) { }

		public override void TogglePower()
		{
			if (_device.IsEnabled())
			{
				_device.Disable();
			}
			else
			{
				_device.Enable();
			}
		}

		public override void VolumeUp()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change volume. Device is disabled.");
				return;
			}

			if (_device.GetVolume() < 100)
			{
				_device.SetVolume(_device.GetVolume() + 10);
			}
			else
			{
				_device.SetVolume(100);
			}
		}

		public override void VolumeDown()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change volume. Device is disabled.");
				return;
			}

			if (_device.GetVolume() > 10)
			{
				_device.SetVolume(_device.GetVolume() - 10);
			}
			else
			{
				_device.SetVolume(0);
			}
		}

		public override void ChannelUp()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change channel. Device is disabled.");
				return;
			}

			_device.SetChannel(_device.GetChannel() + 1);
		}

		public override void ChannelDown()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change channel. Device is disabled.");
				return;
			}

			_device.SetChannel(_device.GetChannel() - 1);
		}
	}
}
