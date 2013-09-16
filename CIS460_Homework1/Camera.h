#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtx/transform.hpp"

class Camera {
public:
	glm::vec3 up;
	glm::vec3 eye;
	glm::vec3 view;
	float fovX;
	float fovY;
};