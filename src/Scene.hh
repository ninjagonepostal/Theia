/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_THEIA_SCENE_INC
#	define ENTROPY_THEIA_SCENE_INC

#	include "Drawable.hh"
#	include "Camera.hh"
#	include "DefaultedList.hh"

	namespace Entropy
	{
		namespace Theia
		{
			class Scene
			{
				public:
					Drawable();
					virtual ~Drawable();
					virtual void Draw(const std::chrono::duration<double> &);
				private:
					DefaultedList<Camera> _cameras;
					std::list<std::shared_ptr<Drawable>> _items;
			};
		}
	}

#endif
