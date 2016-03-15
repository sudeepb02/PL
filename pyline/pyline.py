import pygame
pygame.init()
red = (255,0,0)
green = (0,255,0)
blue = (0,0,255)
black = (0,0,0)
white = (255,255,255)
col = (0,0,10)

s1 = pygame.display.set_mode((720,1080))	#dimension of window
pygame.display.set_caption("Line Types ")	#Title bar

s1.fill(white)		#set background of window to white

pygame.draw.line(s1,red,[100,100],[100,500],2)

pygame.draw.line(s1,green,[200,100],[200,500],10)

for i in range(0,400):
	#print i
	if i%3==0:
		pygame.draw.line(s1,blue,[250,100+i],[250,100+i+1],2)
for i in range(0,180):
	if i%10==0:
		pygame.draw.line(s1,black,[400,100+i],[400,100+i+3],3)

#for drawing kite
pygame.draw.line(s1,black,[300,200],[400,100],4)
pygame.draw.line(s1,black,[400,100],[500,200],4)
pygame.draw.line(s1,black,[500,200],[400,300],4)
pygame.draw.line(s1,black,[400,300],[300,200],4)

#for drawing triangle
pygame.draw.line(s1,blue,[400,250],[350,350])
pygame.draw.line(s1,blue,[350,350],[450,350])
pygame.draw.line(s1,blue,[450,350],[400,250])

#update the window
pygame.display.update()

done = True
while done:
	for event in pygame.event.get():
		if event.type==pygame.QUIT:
			done = False

pygame.quit()

			
	
