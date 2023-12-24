#include "camera.h"
#include "libft.h"

// (u, v, w) are the orthonormal basis of the camera.
// The distance between the camera and the viewport is 1.
t_camera new_camera(t_camera_conf conf, t_vec3 vup, double aspect_ratio)
{
	const double fov_rad = ft_to_radian(conf.fov);
	const double viewport_width = 2.0 * tan(fov_rad / 2.0);
	const double viewport_height = viewport_width / aspect_ratio;
	const t_vec3 w = vec3_normalize(conf.orientation);
	const t_vec3 u = vec3_normalize(vec3_cross(w, vup));
	const t_vec3 v = vec3_cross(w, u);
	t_camera camera;

	camera.origin = conf.position;
	camera.viewport_horizontal = vec3_scale(u, viewport_width);
	camera.viewport_vertical = vec3_scale(v, viewport_height);
	camera.upper_left_corner = vec3_add_scaled(
		vec3_add(camera.origin, w),
		vec3_add(camera.viewport_horizontal, camera.viewport_vertical),
		-0.5
	);
	return (camera);
}

// (x, y) are coordinates on the viewport, normalized between [0, 1].
t_ray camera_get_ray(t_camera camera, double x, double y)
{
	const t_vec3 screen_point = vec3_add_3(
		camera.upper_left_corner,
		vec3_scale(camera.viewport_horizontal, x),
		vec3_scale(camera.viewport_vertical, y)
	);
	return (new_ray(camera.origin, vec3_sub(screen_point, camera.origin)));
}
