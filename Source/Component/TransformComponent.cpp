#include "TransformComponent.hpp"

#include <glm/gtx/transform.hpp>
#include <glm\gtx\string_cast.hpp>
#include <iostream>

#define PI 3.14159265358979323846f

TransformComponent::TransformComponent() noexcept:
	m_MatTransform(1.0f)
{
}

TransformComponent::TransformComponent(const glm::vec3& startingPosition) noexcept :
	m_MatTransform(1.0f)
{
	Translate(startingPosition);
}

TransformComponent& TransformComponent::operator=(const TransformComponent&) noexcept
{
	return *this;
}

void TransformComponent::Translate(const glm::vec3& translation)
{
	m_MatTransform *= glm::translate(glm::mat4(1.0f), translation);
}

void TransformComponent::RotateX(float deg)
{
	m_MatTransform *= glm::rotate(deg * PI / 180.0f, glm::vec3(1.0f, 0.0f, 0.0f));
}

void TransformComponent::RotateY(float deg)
{
	m_MatTransform *= glm::rotate(deg * PI / 180.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}

void TransformComponent::RotateZ(float deg)
{
	m_MatTransform *= glm::rotate(deg * PI / 180.0f, glm::vec3(0.0f, 0.0f, 1.0f));
}