import pygame

# Initialization
pygame.init()
screen = pygame.display.set_mode((1920, 1080))
clock = pygame.time.Clock()
running = 1

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = 0

    screen.fill("white")

    pygame.display.flip()

    clock.tick(60)

pygame.quit()